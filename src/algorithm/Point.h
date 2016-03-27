//
// Created by Bijoy Kochar on 3/27/16.
//

#ifndef MEDICALIMAGEPROCESSING_POINT_H
#define MEDICALIMAGEPROCESSING_POINT_H

#include <cmath>

class Point {
public:
    float x, y, z;

    Point();

    Point(float x, float y, float z);

    Point add(Point a);

    Point mult(float value);

    short sx();
    short sy();
    short sz();
};

#endif //MEDICALIMAGEPROCESSING_POINT_H
