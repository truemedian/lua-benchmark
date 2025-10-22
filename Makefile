CFLAGS = -g -O2 -Wall -Wextra -Wpedantic -std=c++23 -fsanitize=undefined

LUA51_CFLAGS = $(shell pkg-config --cflags lua5.1)
LUA51_LIBS = $(shell pkg-config --libs lua5.1)

LUA52_CFLAGS = $(shell pkg-config --cflags lua5.2)
LUA52_LIBS = $(shell pkg-config --libs lua5.2)

LUA53_CFLAGS = $(shell pkg-config --cflags lua5.3)
LUA53_LIBS = $(shell pkg-config --libs lua5.3)

LUA54_CFLAGS = $(shell pkg-config --cflags lua5.4)
LUA54_LIBS = $(shell pkg-config --libs lua5.4)

LUAJIT_CFLAGS = $(shell pkg-config --cflags luajit)
LUAJIT_LIBS = $(shell pkg-config --libs luajit)

TASKSET = taskset -c 3
BENCH_ARGS =

bench-lua51: src/main.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LUA51_CFLAGS) $(LUA51_LIBS)

bench-lua52: src/main.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LUA52_CFLAGS) $(LUA52_LIBS)

bench-lua53: src/main.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LUA53_CFLAGS) $(LUA53_LIBS)

bench-lua54: src/main.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LUA54_CFLAGS) $(LUA54_LIBS)

bench-luajit: src/main.cpp
	$(CXX) -o $@ $< $(CFLAGS) $(LUAJIT_CFLAGS) $(LUAJIT_LIBS)

bench: bench-lua51 bench-lua52 bench-lua53 bench-lua54 bench-luajit

run-lua51: bench-lua51
	$(TASKSET) ./bench-lua51 $(BENCH_ARGS)

run-lua52: bench-lua52
	$(TASKSET) ./bench-lua52 $(BENCH_ARGS)

run-lua53: bench-lua53
	$(TASKSET) ./bench-lua53 $(BENCH_ARGS)

run-lua54: bench-lua54
	$(TASKSET) ./bench-lua54 $(BENCH_ARGS)

run-luajit: bench-luajit
	$(TASKSET) ./bench-luajit $(BENCH_ARGS)

run-luajit-interpreter: bench-luajit
	$(TASKSET) ./bench-luajit --interpreter $(BENCH_ARGS)

run: bench-lua51 bench-lua52 bench-lua53 bench-lua54 bench-luajit
	$(TASKSET) ./bench-lua51 $(BENCH_ARGS)
	$(TASKSET) ./bench-lua52 $(BENCH_ARGS)
	$(TASKSET) ./bench-lua53 $(BENCH_ARGS)
	$(TASKSET) ./bench-lua54 $(BENCH_ARGS)
	$(TASKSET) ./bench-luajit $(BENCH_ARGS)
	$(TASKSET) ./bench-luajit --interpreter $(BENCH_ARGS)

clean:
	rm bench-lua51 bench-lua52 bench-lua53 bench-lua54 bench-luajit

cleanall: clean
	rm -r results

bench-lua51 bench-lua52 bench-lua53 bench-lua54 bench-luajit: src/bench.hpp src/timer.hpp