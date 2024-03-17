SHELL:=/bin/bash

all: vector_main.x

%.x: %.o vector_ops.o
	g++ $^ -o $@

vector_test.x: vector_test.o vector_ops.o
	g++ $^ -o $@ -l Catch2Main -l Catch2

test: vector_test.x
	./vector_test.x

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o *.x