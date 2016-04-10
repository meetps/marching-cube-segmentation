//
// Created by Bijoy Kochar on 3/27/16.
//

#ifndef MEDICALIMAGEPROCESSING_POINT_H
#define MEDICALIMAGEPROCESSING_POINT_H

#include <cmath>
#include <ostream>

using namespace std;

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

    void print(ostream &out);
};

class Triangle {
public:
    Point p1, p2, p3;

    Triangle(Point p1, Point p2, Point p3);

    Triangle();

    void print(ostream &out);

    void render(ostream &out);
};

#endif //MEDICALIMAGEPROCESSING_POINT_H
