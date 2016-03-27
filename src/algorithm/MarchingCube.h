//
// Created by Bijoy Kochar on 3/27/16.
//

#ifndef MEDICALIMAGEPROCESSING_MARCHINGCUBE_H
#define MEDICALIMAGEPROCESSING_MARCHINGCUBE_H

#include "EdgeTable.h"

class MarchingCube {
public:
    short ***image;
    short sx, sy, sz;

    MarchingCube(short ***image, short sx, short sy, short sz);

    void march(short contour);

};

#endif //MEDICALIMAGEPROCESSING_MARCHINGCUBE_H
