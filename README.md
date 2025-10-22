
# Lua Benchmarks

This repository contains a collection of benchmarks that are used to measure the performance of Lua interpreters and
implementations, particularly in choosing which algorithm is best suited for a given task.

**[View Benchmarks](benchmarks/)**

## Adding a new Benchmark

To add a new benchmark, create a new directory in the `benchmarks/` directory. This directory must include at least a
`meta.lua` file that describes the benchmark of the form:

```lua
return {
  name = "benchmark_name",      -- The name of the benchmark
  expected = "expected_output", -- The expected output of the benchmark
  {
    id = "test_case_1",         -- descriptive name of the test case
  }
  {
    lua51 = true,               -- indicates this test case should be skipped for Lua 5.1
    id = "test_case_2",         -- descriptive name of the test case
  }
}
```

Each test case can include additional fields to specify which Lua versions to skip. The valid fields are `lua51`, `lua52`,
`lua53`, `lua54`, `luajit`, and `luajit_interpreter`. If a field is set to `true`, the test case will be skipped for that
Lua version.

The benchmark directory should also include one or more Lua files that implement the benchmark logic. Each Lua file
should correspond to a test case defined in the `meta.lua` file and be named incrementally (e.g. `1.lua`, `2.lua`, etc.).

Each benchmark can also include an optional `setup.lua` file that contains setup code to be executed before running the
benchmark test cases and a `setup_local.lua` file to be executed on each iteration.

The resulting code that will be tested is of the form:

```lua
<setup.lua content>

return function(__n)
    <setup_local.lua content>
    for __i = 1, __n do
        <test case content>
    end
end
```

The function will then be executed with a given number of iterations `__n`, tuned such that we can measure the execution
time accurately.

## Running Benchmarks

Benchmarks are run on one-at-a-time on a quiet machine to minimize noise in the results.

```sh
$ cpupower -c 3,7 frequency-set -g performance
$ cpupower -c 3,7 frequency-set -u 3400MHz
$ cpupower -c 3,7 frequency-set -d 3400MHz
$ systemctl set-property --runtime user.slice AllowedCPUs=0-2,4-6
$ systemctl set-property --runtime system.slice AllowedCPUs=0-2,4-6
$ systemctl set-property --runtime machine.slice AllowedCPUs=0-2,4-6
$ systemctl set-property --runtime workload.slice AllowedCPUs=3,7
$ systemd-run --scope -p Slice=workload.slice make run
```

This prevents essentially all other processes from running on the CPUs used for benchmarking and eliminates nearly all
CPU frequency scaling.

The `make run` command will execute all benchmarks across all supported Lua versions and collect the results in the
`results/` directory.
