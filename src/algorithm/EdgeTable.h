//
// Created by Bijoy Kochar on 3/27/16.
//

#ifndef MEDICALIMAGEPROCESSING_EDGETABLE_H
#define MEDICALIMAGEPROCESSING_EDGETABLE_H

#include "Point.h"

class EdgeTable {

public:
    bool nodeParity[8];
    bool edgeIntersections[12];

    EdgeTable();

    // x,y,z are the least x, y, z value corner of the cell
    void setValues(short ***image, short x, short y, short z, short contour);

    short *getIntersection(short ***image, short x, short y, short z, short contour, short edge);

    static short getPointIntensity(short ***image, short x, short y, short z, short index);

    static Point getPoint(short x, short y, short z, short index);

    static short *getPoints(short edge);
};

#endif //MEDICALIMAGEPROCESSING_EDGETABLE_H
