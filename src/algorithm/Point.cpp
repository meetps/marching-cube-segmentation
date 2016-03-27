//
// Created by Bijoy Kochar on 3/27/16.
//

#include "Point.h"

Point::Point() { }

Point::Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point Point::add(Point a) {
    return Point(a.x + x, a.y + y, a.z + z);
}

Point Point::mult(short value) {
    return Point(value * x, value * y, value * z);
}

short Point::sx() {
    return round(x);
}

short Point::sy() {
    return round(y);
}

short Point::sz() {
    return round(z);
}