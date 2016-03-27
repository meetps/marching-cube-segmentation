//
// Created by Bijoy Kochar on 3/27/16.
//

#include "MarchingCube.h"

MarchingCube::MarchingCube(short ***image, short sx, short sy, short sz) {
    this->image = image;
    this->sx = sx;
    this->sy = sy;
    this->sz = sz;
}

void MarchingCube::march(short contour) {
    list <Triangle> triangles;
    for (int i = 0; i < sx - 1; i++) {
        for (int j = 0; j < sy - 1; j++) {
            for (int k = 0; k < sz - 1; k++) {
                EdgeTable edgeTable;
                edgeTable.setValues(image, i, j, k, contour);
                triangles.splice(triangles.end(), edgeTable.getTriangles(image, i, j, k, contour));
            }
        }
    }
}