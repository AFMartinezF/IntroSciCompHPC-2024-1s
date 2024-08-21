SHELL:=/bin/bash

all: 9.2main_factorial.x 9.2test_factorial.x

%.x: %.o 9.2factorial.o
	g++ $^ -o $@

9.2test_factorial.x: 9.2test_factorial.o 9.2factorial.o
	g++ $^ -o $@ -l Catch2Main -l Catch2 

test: 9.2test_factorial.x
	./9.2test_factorial.x

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o 