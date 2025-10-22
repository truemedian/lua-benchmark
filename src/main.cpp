#include "bench.hpp"
#include "timer.hpp"

#include <fstream>
#include <iostream>
#include <lua.hpp>

lua_State* build_state() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    return L;
}

void usage(const char* prog_name) {
    std::cout << "Usage: " << prog_name << " [options] -- [benchmarks]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --help       Show this help message" << std::endl;
    std::cout << "  --tsc Hz     Set the TSC frequency" << std::endl;
}

bool argparse(int argc, char** argv, int& argi) {
    const char* prog_name = argc > 0 ? argv[0] : "bench";
    int index = 1;

    for (; index < argc; ++index) {
        std::string arg = argv[index];

        if (arg == "--help") {
            usage(prog_name);
            return false;
        } else if (arg == "--tsc") {
            uint64_t freq = std::strtoull(argv[++index], nullptr, 10);
            if (freq == 0) {
                std::cerr << "invalid TSC frequency: " << argv[index] << std::endl;
                usage(prog_name);
                return false;
            }

            timer::set_tsc_frequency(freq);
        } else if (arg == "--interpreter") {
            bench::use_interpreter = true;
        } else if (arg == "--") {
            ++index;
            break;
        } else {
            std::cerr << "unknown argument: " << arg << std::endl;
            usage(prog_name);
            return false;
        }
    }

    argi = index;
    // No arguments to parse for now
    return true;
}

void run_benchmark(lua_State* L, const std::string& path) {
    bench::benchmark bm("benchmark/" + path);
    bm.load(L);
    bm.do_all_the_work(L);
}

void run_all_benchmarks(lua_State* L) {
    for (const auto& entry : std::filesystem::directory_iterator("benchmark")) {
        if (!entry.is_directory())
            continue;

        run_benchmark(L, entry.path().filename().string());
    }
}

int main(int argc, char** argv) {
    if (!timer::init())
        return 1;

    int arg = 0;
    argparse(argc, argv, arg);

    lua_State* L = build_state();

    bench::detect_environment(L);
    std::cerr << "[bench] info: running on " << bench::environment_name << " " << bench::environment_path << std::endl;

    bench::disable_garbage_collection(L);

    if (arg < argc) {
        for (; arg < argc; ++arg) {
            run_benchmark(L, argv[arg]);
        }
    } else {
        run_all_benchmarks(L);
    }

    lua_close(L);
    return 0;
}