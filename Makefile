OBJS = main.o StringBuilder.t.o
CXXFLAGS = --std=c++0x -g
CC = clang++

main.o : StringBuilder.t.o StringBuilder.h

StringBuilder.t.o : StringBuilder.h

GTEST :
	g++ -c /usr/src/gtest/src/gtest-all.cc -I/usr/src/gtest/

build: $(OBJS) GTEST
	g++ gtest-all.o $(OBJS) -o StringBuilder.tsk -lrt -lpthread

.PHONY: clean

clean:
	rm gtest-all.o $(OBJS) StringBuilder.tsk

tests: build
	./StringBuilder.tsk


