OBJECTS = main.o List.o Node.o
CXXFLAGS=
LDFLAGS=
CXX=g++


main: main.o List.o Node.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o List.o Node.o 
	$(CXX) -o tests tests.o List.o Node.o

main.o: main.cpp List.h Node.h

tests.o: tests.cpp List.h Node.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f List.o tests.o main.o Node.o