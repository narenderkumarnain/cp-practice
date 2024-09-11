# FILE ?= default.cpp

run: $(FILE)
g++-14 -std=c++17 -o ./a.out $(FILE)
	./a.out < input.txt > output.txt