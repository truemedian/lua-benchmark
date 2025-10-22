#pragma once

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <lua.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "timer.hpp"

#ifndef LUA_OK
#    define LUA_OK 0
#endif

#if LUA_VERSION_NUM <= 501
#    define lua_rawlen lua_objlen
#endif

namespace bench {

// take this many samples per case
static unsigned measure_iterations = 10'000;

// average the tuning over this many iterations
static unsigned tune_iterations = 10;

// by default aim for 1ms per measurement
static unsigned tune_target = 1'000'000;

static std::string environment_name = "missing";
static std::string environment_path = "missing";
static bool use_interpreter = false;

void detect_environment(lua_State* L) {
    luaL_dostring(L,
        "if pcall(require, 'jit') then\n"
        "  jit = require('jit')\n"
        "  ffi = require('ffi')\n"
        "  require('table.new')\n"
        "  require('table.clear')\n"
        "  return jit.version, 'luajit'\n"
        "end\n"
        "return _VERSION, (_VERSION:lower():gsub('[%s%p]', ''))\n");

    environment_path = lua_tostring(L, -1);
    environment_name = lua_tostring(L, -2);
    lua_pop(L, 2);

    if (environment_path == "luajit" && use_interpreter) {
        std::cerr << "[bench] info: forcing LuaJIT interpreter mode" << std::endl;
        luaL_dostring(L,
            "jit.off()\n");

        environment_name += " (interpreter)";
        environment_path = "luajit_interpreter";
    }
}

void disable_garbage_collection(lua_State* L) {
    luaL_dostring(L,
        "collectgarbage('stop')\n");
}

void full_garbage_collection(lua_State* L) {
    luaL_dostring(L,
        "collectgarbage('collect')\n"
        "collectgarbage('collect')\n"
        "collectgarbage('collect')\n"
        "collectgarbage('stop')\n");
}

struct result {
    std::string name;
    unsigned id = 0;

    std::vector<double> samples;
    lua_Integer parameter = 1;

    void add_sample(int64_t sample) {
        samples.push_back(double(sample) / double(parameter));
    }

    void done() {
        std::sort(samples.begin(), samples.end());
    }

    double min() const {
        if (samples.empty())
            return 0.0;
        return samples.front();
    }

    double q25() const {
        if (samples.empty())
            return 0.0;
        size_t index = samples.size() / 4;
        return samples[index];
    }

    double median() const {
        if (samples.empty())
            return 0.0;
        size_t n = samples.size();
        return samples[n / 2];
    }

    double q75() const {
        if (samples.empty())
            return 0.0;
        size_t index = (samples.size() * 3) / 4;
        return samples[index];
    }

    double max() const {
        if (samples.empty())
            return 0.0;
        return samples.back();
    }

    double average() const {
        if (samples.empty())
            return 0.0;

        double sum = 0;
        for (double sample : samples)
            sum += sample;

        return sum / static_cast<double>(samples.size());
    }

    double stddev() const {
        if (samples.size() < 2)
            return 0.0;

        double avg = average();
        double sum_sq_diff = 0.0;

        for (double sample : samples) {
            double diff = sample - avg;
            sum_sq_diff += diff * diff;
        }

        return std::sqrt(sum_sq_diff / static_cast<double>(samples.size() - 1));
    }

    void write(unsigned id) const {
        std::filesystem::create_directories("results/" + name + "/" + environment_path);

        std::ofstream file("results/" + name + "/" + environment_path + "/" + std::to_string(id) + ".lua");
        if (!file) {
            std::cerr << "[bench] error: could not write results to file" << std::endl;
            return;
        }

        file << "return {\n";
        file << "parameter = " << parameter << ",\n";
        file << "min = " << min() << ",\n";
        file << "q25 = " << q25() << ",\n";
        file << "median = " << median() << ",\n";
        file << "q75 = " << q75() << ",\n";
        file << "max = " << max() << ",\n";
        file << "average = " << average() << ",\n";
        file << "stddev = " << stddev() << ",\n";
        file << "samples = {\n";
        for (double sample : samples) {
            file << sample << ",\n";
        }
        file << "}\n";
        file << "}\n";
    }
};

struct benchmark {
    std::string path;
    std::string setup = {};
    std::string setup_local = {};

    int saved_top = 0;
    int metadata = LUA_NOREF;
    unsigned current_id = 0;

    benchmark(std::string path)
        : path(std::move(path)) { }

    static std::string read_file(const std::string& path) {
        std::ifstream file(path);
        if (!file)
            return {};

        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    bool load(lua_State* L) {
        saved_top = lua_gettop(L);

        std::string metadata_content = read_file(path + "/meta.lua");
        if (metadata_content.empty()) {
            std::cerr << "[bench] error: no meta.lua found in '" << path << "'" << std::endl;
            return false;
        }

        int status = luaL_dostring(L, metadata_content.c_str());
        if (status != LUA_OK) {
            std::cerr << "[bench] error loading '" << path << "': " << lua_tostring(L, -1) << std::endl;
            return false;
        }

        if (!lua_istable(L, -1)) {
            std::cerr << "[bench] failed to load '" << path << "': result not a table" << std::endl;
            return false;
        }

        metadata = luaL_ref(L, LUA_REGISTRYINDEX);

        setup = read_file(path + "/setup.lua");
        setup_local = read_file(path + "/setup_local.lua");

        return true;
    }

    void discard(lua_State* L) {
        if (metadata != LUA_NOREF) {
            luaL_unref(L, LUA_REGISTRYINDEX, metadata);
            metadata = LUA_NOREF;
        }

        lua_settop(L, saved_top);
    }

    std::string name(lua_State* L) const {
        lua_rawgeti(L, LUA_REGISTRYINDEX, metadata);
        lua_getfield(L, -1, "name");
        std::string result = lua_tostring(L, -1);
        lua_pop(L, 2); // pop name and table
        return result;
    }

    unsigned count(lua_State* L) const {
        lua_rawgeti(L, LUA_REGISTRYINDEX, metadata);
        int size = lua_rawlen(L, -1);
        lua_pop(L, 1); // pop table
        return size;
    }

    bool should_run(lua_State* L, unsigned id) const {
        lua_rawgeti(L, LUA_REGISTRYINDEX, metadata);
        lua_rawgeti(L, -1, id);
        lua_getfield(L, -1, environment_path.c_str());
        bool skip = lua_toboolean(L, -1);
        lua_pop(L, 3); // pop skip, entry, table
        return !skip;
    }

    bool prepare(lua_State* L, unsigned id) {
        if (current_id != 0) {
            lua_pop(L, 1); // remove previous function
            current_id = 0;
        }

        std::string test_content = read_file(path + "/" + std::to_string(id) + ".lua");
        if (test_content.empty())
            return false;

        std::ostringstream buffer;
        buffer << setup << "\n";
        buffer << "return function(__n)\n";
        buffer << "local out\n";
        buffer << setup_local << "\n";
        buffer << "for __i = 1, __n do\n";
        buffer << test_content << "\n";
        buffer << "end\n";
        buffer << "return out\n";
        buffer << "end\n";

        int status = luaL_dostring(L, buffer.str().c_str());
        if (status != LUA_OK) {
            std::cerr << "[bench] error preparing '" << path << "/" << id << "': " << lua_tostring(L, -1) << std::endl;
            return false;
        }

        current_id = id;
        return true;
    }

    int64_t run(lua_State* L, lua_Integer n) const {
        bench::full_garbage_collection(L);

        lua_pushvalue(L, -1); // copy function
        lua_pushinteger(L, n); // push __n

        uint64_t start = timer::read();
        int status = lua_pcall(L, 1, 0, 0);
        int64_t run1 = timer::taken(start);
        if (status != LUA_OK) {
            std::cerr << "[bench] error running '" << path << "' test " << current_id << ": " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1);
            return -1;
        }

        lua_pushvalue(L, -1); // copy function
        lua_pushinteger(L, 2 * n); // push __n

        start = timer::read();
        status = lua_pcall(L, 1, 0, 0);
        int64_t run2 = timer::taken(start);
        if (status != LUA_OK) {
            std::cerr << "[bench] error running '" << path << "' test " << current_id << ": " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1);
            return INT64_MIN;
        }

        return run2 - run1;
    }

    std::tuple<lua_Integer, lua_Integer> tune_bounds(lua_State* L) const {
        lua_Integer low_parameter = 0;
        lua_Integer high_parameter = 0;

        for (unsigned i = 0; i < tune_iterations; ++i) {
            lua_Integer n = 128;

            while (true) {
                int64_t taken = run(L, n);
                if (taken == INT64_MIN)
                    break;
                if (taken <= 0)
                    continue;

                int64_t elapsed = timer::tick2ns(taken);
                if (elapsed > tune_target)
                    break;

                n *= 2;
            }

            low_parameter += n / 2;
            high_parameter += n * 2;
        }

        return { low_parameter / tune_iterations, high_parameter / tune_iterations };
    }

    lua_Integer tune(lua_State* L) const {
        auto [low_bound, high_bound] = tune_bounds(L);

        lua_Integer best = 0;

        for (unsigned i = 0; i < tune_iterations; ++i) {
            lua_Integer low = low_bound;
            lua_Integer high = high_bound;

            while (low + 1 < high) {
                lua_Integer mid = (low + high) / 2;

                int64_t taken = run(L, mid);
                if (taken == INT64_MIN)
                    return 0;
                if (taken <= 0)
                    continue;

                int64_t elapsed = timer::tick2ns(taken);
                if (elapsed < tune_target) {
                    low = mid;
                } else {
                    high = mid;
                }
            }

            best += low;
        }

        return best / tune_iterations;
    }

    bool measure(lua_State* L, lua_Integer parameter, result& res) {
        std::cerr << "[bench] info: measuring '" << name(L) << "' test " << current_id << " with parameter " << parameter << std::endl;

        res.name = std::filesystem::path(path).filename().string();
        res.id = current_id;
        res.samples.reserve(measure_iterations);
        res.parameter = parameter;

        uint64_t total_elapsed = 0;
        uint64_t last_time = timer::read();

        for (unsigned i = 0; i < measure_iterations; ++i) {
            int64_t taken = run(L, parameter);

            if (taken == INT64_MIN)
                return false;
            if (taken <= 0) {
                --i;
                continue;
            }

            res.add_sample(taken);

            uint64_t now = timer::read();
            total_elapsed += now - last_time;
            last_time = now;

            std::cerr << "\r[bench] info: measured " << (i + 1) << " / " << measure_iterations << " samples in " << timer::tick2ns(total_elapsed) / 1'000'000'000 << " seconds";
            std::cerr.flush();
        }

        std::cerr << "\r\033[2K";
        std::cerr.flush();

        lua_pop(L, 1); // remove function
        current_id = 0;

        res.done();
        return true;
    }

    void do_all_the_work(lua_State* L) {
        for (unsigned i = 1; i <= count(L); ++i) {
            if (!should_run(L, i))
                continue;

            if (!prepare(L, i))
                continue;
            lua_Integer n = tune(L);
            if (n == 0)
                continue;

            bench::result res;
            if (!measure(L, n, res))
                continue;

            res.write(i);
        }
    }
};

}