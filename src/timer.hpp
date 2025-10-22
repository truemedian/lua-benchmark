#pragma once

#include <chrono>
#include <cstdint>
#include <iostream>
#include <thread>
#include <type_traits>

namespace {
struct cpuid_info {
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
};

static inline cpuid_info cpuid(uint32_t leaf) {
    cpuid_info info;

    asm volatile(
        "cpuid"
        : "=a"(info.eax), "=b"(info.ebx), "=c"(info.ecx), "=d"(info.edx)
        : "a"(leaf));
    return info;
}

}

namespace timer {

static int64_t tsc_frequency = 1;
static int64_t overhead = 0;

static inline uint64_t read() {
    uint32_t low, high;
    asm volatile(
        "mfence\n"
        "rdtscp\n"
        "lfence\n"
        : "=a"(low), "=d"(high)
        :
        : "%rcx");
    return ((uint64_t(high) << 32) | uint64_t(low)) - overhead;
}

static inline int64_t taken(uint64_t since) {
    uint64_t now = read();
    return int64_t(now - since);
}

static constexpr unsigned overhead_loop = 1'000'000;
static inline void measure_overhead() {
    int64_t min_overhead = INT64_MAX;
    for (unsigned i = 0; i < overhead_loop; ++i) {
        uint64_t start = read();
        asm volatile("" ::: "memory");
        int64_t current_overhead = taken(start);
        min_overhead = std::min(min_overhead, current_overhead);
    }

    overhead = min_overhead;
}

static inline int64_t measure_frequency() {
    int64_t ticks = 0;
    int64_t nanoseconds = 0;

    // time to guess...
    for (; nanoseconds < 1'000'000'000;) {
        int64_t ns_before = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        uint64_t start = read();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        int64_t distance = taken(start);
        int64_t ns_after = std::chrono::high_resolution_clock::now().time_since_epoch().count();

        nanoseconds += (ns_after - ns_before);
        ticks += distance;
    }

    return int64_t(__int128_t(ticks) * 1'000'000'000 / nanoseconds);
}

static inline bool init() {
    cpuid_info leaf_1h = cpuid(0x1);
    cpuid_info leaf_15h = cpuid(0x15);
    cpuid_info leaf_16h = cpuid(0x16);
    cpuid_info leaf_80000000h = cpuid(0x80000000);

    // Missing TSC feature
    if ((leaf_1h.edx & (1 << 4)) == 0) {
        std::cerr << "[tsc] fatal: TSC not supported!" << std::endl;
        return false;
    }

    // Check if extended CPUID functions are supported
    if (leaf_80000000h.eax < 0x80000007) {
        std::cerr << "[tsc] fatal: invariant TSC not supported!" << std::endl;
        return false;
    }

    cpuid_info leaf_80000007h = cpuid(0x80000007);

    // Invariant TSC not supported
    if ((leaf_80000007h.edx & (1 << 8)) == 0) {
        std::cerr << "[tsc] fatal: invariant TSC not supported!" << std::endl;
        return false;
    }

    measure_overhead();
    int64_t measured_tsc_frequency = measure_frequency();

    // Estimate TSC frequency using the best available method
    if ((leaf_15h.eax != 0) && (leaf_15h.ebx != 0) && (leaf_15h.ecx != 0)) {
        tsc_frequency = (int64_t(leaf_15h.ecx) * int64_t(leaf_15h.ebx)) / int64_t(leaf_15h.eax);
    } else if (leaf_16h.eax != 0) {
        tsc_frequency = int64_t(leaf_16h.eax) * 1'000'000;
    } else {
        tsc_frequency = measured_tsc_frequency;
    }

    std::cerr << "[tsc] info: measured overhead: " << overhead << " ticks" << std::endl;
    std::cerr << "[tsc] info: measured frequency: " << measured_tsc_frequency << " Hz" << std::endl;
    std::cerr << "[tsc] info: using frequency: " << tsc_frequency << " Hz" << std::endl;

    return true;
}

static void set_tsc_frequency(int64_t freq) {
    int64_t diff = freq > tsc_frequency ? freq - tsc_frequency : tsc_frequency - freq;
    if (diff * 100 > tsc_frequency) { // more than 1% difference
        std::cerr << "[tsc] warning: overriding frequency from " << tsc_frequency << " Hz to " << freq << " Hz" << std::endl;
    }

    tsc_frequency = freq;
    std::cerr << "[tsc] info: changed frequency: " << tsc_frequency << " Hz" << std::endl;
}

template<typename T>
    requires std::is_floating_point_v<T>
static inline T tick2ns(T tick) {
    return (tick * 1'000'000'000.0) / T(tsc_frequency);
}

template<typename T>
    requires std::is_integral_v<T>
static inline T tick2ns(T tick) {
    return (__int128_t(tick) * 1'000'000'000) / tsc_frequency;
}

} // namespace timer
