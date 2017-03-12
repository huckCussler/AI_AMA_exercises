CXX=g++
CXXFLAGS=-std=c++0x -Wall -g
OBJS=state.o bfs.o

all: compile run

compile: main.o $(OBJS)
	$(CXX) -g main.o $(OBJS) -o main

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

state.o: state.cc
	$(CXX) $(CXXFLAGS) -c state.cc

bfs.o: bfs.cc
	$(CXX) $(CXXFLAGS) -c bfs.cc

run: main
	./main

clean:
	rm -f *.o main
