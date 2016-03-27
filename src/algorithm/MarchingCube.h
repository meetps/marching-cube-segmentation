//
// Created by Bijoy Kochar on 3/27/16.
//

#ifndef MEDICALIMAGEPROCESSING_MARCHINGCUBE_H
#define MEDICALIMAGEPROCESSING_MARCHINGCUBE_H

#include "EdgeTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class MarchingCube {
public:
    short ***image;
    short sx, sy, sz;

    MarchingCube(short ***image, short sx, short sy, short sz);
    MarchingCube(string filename);

    void march(short contour);
};

#endif //MEDICALIMAGEPROCESSING_MARCHINGCUBE_H
