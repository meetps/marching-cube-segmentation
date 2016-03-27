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

Point Point::mult(float value) {
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

void Point::print(ostream &out) {
    out << "(" << x << ", " << y << ", " << z << ")";
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle() { }

void Triangle::print(ostream &out) {
    out << "[";
    p1.print(out);
    out << ", ";
    p2.print(out);
    out << ", ";
    p3.print(out);
    out << "]" << endl;
}