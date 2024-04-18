CPP=g++
ARGS=-g -std=c++17

all:
	$(CPP) main.cpp BackgroundColor.cpp $(ARGS) -o main