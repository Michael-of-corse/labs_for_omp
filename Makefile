CC=clang++
CLANG_DIRS= -I/usr/include/c++/11 -I/usr/include/x86_64-linux-gnu/c++/11
LDCLANG_DIRS=/usr/lib/gcc/x86_64-linux-gnu/11

all:
	$(CC) -fopenmp $(CLANG_DIRS) -L $(LDCLANG_DIRS) magic_suqare.cpp -o ./build/main

run:
	./build/main
