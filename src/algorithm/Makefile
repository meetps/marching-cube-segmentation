CC=g++

BIN=marching_cube.out
UNITBIN=unit_bin.out
SRCS=main.cpp MarchingCube.cpp EdgeTable.cpp Point.cpp
UNIT=unit_test.cpp MarchingCube.cpp EdgeTable.cpp Point.cpp
INCLUDES=Point.h EdgeTable.h MarchingCube.h

.phony: unit all clean

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	g++ --std=c++11 $(SRCS) -o $(BIN)

unit: $(UNIT) $(INCLUDES)
	g++ --std=c++11 $(UNIT) -o $(UNITBIN)

clean:
	rm -f *~ *.o $(BIN)
	rm -f *~ *.o $(UNITBIN)
