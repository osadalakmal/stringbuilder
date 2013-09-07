OBJS = main.o StringBuilder.t.o

main.o : StringBuilder.t.o StringBuilder.h

StringBuilder.t.o : StringBuilder.h

build: $(OBJS)
	g++ -c /usr/src/gtest/src/gtest-all.cc -I/usr/src/gtest/
	g++ gtest-all.o $(OBJS) -o StringBuilder.tsk -lrt -lpthread

.PHONY: clean

clean:
	rm gtest-all.o $(OBJS) StringBuilder.tsk


