CC=g++
CFLAGS= -Wall -std=c++11
BUILD=build
SRC=src/

build:
	mkdir -p $(BUILD)

compile: build
	$(CC) $(CFLAGS) main.cpp $(SRC)*.cpp -o $(BUILD)/main

run:
	./$(BUILD)/main

all: compile run
