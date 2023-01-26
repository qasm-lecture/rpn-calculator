
CXXFLAGS=-std=c++17

default: main

fuzz_main: main.cpp
	afl-g++ $(CXXFLAGS) -o fuzz_main main.cpp

fuzz: fuzz_main
	rm -rf out
	afl-fuzz -i in -o out -- ./fuzz_main

clean:
	rm -rf main fuzz_main out
