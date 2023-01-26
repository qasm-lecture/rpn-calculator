
CC=c++
CFLAGS=-std=c++20
LDFLAGS=-lgtest

default: main

main: main.o lib.o

test: test.o lib.o

fuzz_main: main.cpp lib.cpp
	afl-g++ $(CFLAGS) -o fuzz_main main.cpp lib.cpp

fuzz: fuzz_main
	rm -rf out
	afl-fuzz -i in -o out -- ./fuzz_main

clean:
	rm -rf main fuzz_main out test *.o
