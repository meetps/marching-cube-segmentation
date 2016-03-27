//
// Created by Bijoy Kochar on 3/27/16.
//

#include "EdgeTable.h"

short getImageValue(short **image, Point point) {
    return image[point.sx()][point.sy()][point.sz()];
}

short EdgeTable::getPointIntensity(short ***image, short x, short y, short z, short index) {
    Point point = getPoint(x, y, z, index);
    return getImageValue(image, point);
}

Point EdgeTable::getPoint(short x, short y, short z, short index) {
    switch (index) {
        case 0:
            return Point(x, y, z);
        case 1:
            return Point(x + 1, y, z);
        case 2:
            return Point(x + 1, y, z + 1);
        case 3:
            return Point(x, y, z + 1);
        case 4:
            return Point(x, y + 1, z);
        case 5:
            return Point(x + 1, y + 1, z);
        case 6:
            return Point(x + 1, y + 1, z + 1);
        case 7:
            return Point(x, y + 1, z + 1);
        default:
            return Point(x, y, z);
    }
}

short *EdgeTable::getPoints(short edge) {
    switch (edge) {
        case 0:
            return {0, 1};
        case 1:
            return {1, 2};
        case 2:
            return {2, 3};
        case 3:
            return {3, 0};
        case 4:
            return {4, 5};
        case 5:
            return {5, 6};
        case 6:
            return {6, 7};
        case 7:
            return {7, 4};
        case 8:
            return {0, 4};
        case 9:
            return {1, 5};
        case 10:
            return {2, 6};
        case 11:
            return {3, 7};
        default:
            return {0, 1};
    }

}

void EdgeTable::setValues(short ***image, short x, short y, short z, short contour) {
    for (int i = 0; i < 8; i++) {
        nodeParity[i] = getPointIntensity(image, x, y, z, i) < contour;
    }

    for (int i = 0; i < 12; i++) {
        short *points = getPoints(i);
        edgeIntersections[0] = nodeParity[points[0]] ^ nodeParity[points[1]];
    }
}

Point EdgeTable::getIntersection(short ***image, short x, short y, short z, short contour, short edge) {
    short *points = getPoints(i);
    Point p1 = getPoint(x, y, z, points[0]);
    Point p2 = getPoint(x, y, z, points[1]);

    short v1 = getImageValue(image, p1);
    short v2 = getImageValue(image, p2);

    float scale = (1.0 * (contour - v1))/ (v2 - v1);
    Point p = p1.mult(-1);
    p = p2.add(p);
    p = p.mult(scale);
    p = p1.add(p);

    return p;
}