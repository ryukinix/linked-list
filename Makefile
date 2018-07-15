all: main

*.o: *.cpp
	g++ -c $<

main: *.o main.cpp
	g++ $^ -o $@

test: main
	./main


.PHONY: test
