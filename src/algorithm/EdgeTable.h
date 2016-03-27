//
// Created by Bijoy Kochar on 3/27/16.
//

#ifndef MEDICALIMAGEPROCESSING_EDGETABLE_H
#define MEDICALIMAGEPROCESSING_EDGETABLE_H

#include "Point.h"
#include <list>
#include <iostream>

using namespace std;

class EdgeTable {

public:
    bool nodeParity[8];
    bool edgeIntersections[12];

    EdgeTable();

    // x,y,z are the least x, y, z value corner of the cell
    void setValues(short ***image, short x, short y, short z, short contour);

    Point getIntersection(short ***image, short x, short y, short z, short contour, short edge);

    static short getPointIntensity(short ***image, short x, short y, short z, short index);

    static Point getPoint(short x, short y, short z, short index);

    static void getPoints(short edge, short arr[]);

    short getEdgeCaseNumber();

    short getNodeCaseNumber();

    list<Triangle> getTriangles(short ***image, short x, short y, short z, short contour);
};

#endif //MEDICALIMAGEPROCESSING_EDGETABLE_H
