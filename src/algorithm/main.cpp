//
// Created by Bijoy Kochar on 3/27/16.
//

#include "Point.h"
#include "EdgeTable.h"
#include "MarchingCube.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    MarchingCube cube("../../data/VSD.Brain.XX.O.MR_Flair/Flair.csv");
    list<Triangle> triangles = cube.march(1200);

    ofstream fout;
    fout.open("triangles.txt");

}
