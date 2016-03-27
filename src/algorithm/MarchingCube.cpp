//
// Created by Bijoy Kochar on 3/27/16.
//

#include "MarchingCube.h"
#include <iostream>

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

    for (Triangle triangle : triangles) {
        triangle.print(cout);
    }
}

MarchingCube::MarchingCube(string filename) {
    ifstream mhaReader;
    mhaReader.open(filename);
    if (mhaReader.is_open()) {
        short val;
        mhaReader >> sx;
        mhaReader >> sy;
        mhaReader >> sz;

        image = new short **[sx];
        for (int i = 0; i < sx; i++) {
            image[i] = new short *[sy];
            for (int j = 0; j < sy; j++) {
                image[i][j] = new short[sz];
            }
        }

        int max = 0;

        for (int k = 0; k < sz; k++) {
            for (int j = 0; j < sy; j++) {
                for (int i = 0; i < sx; i++) {
                    mhaReader >> val;
                    image[i][j][k] = val;
                    if (val > max) {
                        max = val;
                    }
                }
            }
        }
    }
}