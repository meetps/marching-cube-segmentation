CC=g++

BIN=marching_cube.out
SRCS=unit_test.cpp MarchingCube.cpp EdgeTable.cpp Point.cpp
INCLUDES=Point.h EdgeTable.h MarchingCube.h

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ --std=c++11 $(SRCS) -o $(BIN)

clean:
	rm -f *~ *.o $(BIN)
