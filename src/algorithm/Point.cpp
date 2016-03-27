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

Triangle::Triangle(Point p1, Point p2, Point p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle::Triangle() { }

void Triangle::print(ostream &out) {
    out<<"{"<<endl;
    out<<"\t"<<p1.x<<","<<p1.y<<","<<p1.z<<","<<endl;
    out<<"\t"<<p2.x<<","<<p2.y<<","<<p2.z<<","<<endl;
    out<<"\t"<<p3.x<<","<<p3.y<<","<<p3.z<<","<<endl;
    out<<"}"<<endl;
}