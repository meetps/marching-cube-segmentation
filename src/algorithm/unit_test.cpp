//
// Created by Bijoy Kochar on 3/27/16.
//

#include "Point.h"
#include "EdgeTable.h"
#include "MarchingCube.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

void setToSphere(short ***image, short sx, short sy, short sz, short max_value, short r) {
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            for (int k = 0; k < sz; k++) {
                float value = (i - (sx / 2)) * (i - (sx / 2)) + (j - (sy / 2)) * (j - (sy / 2)) +
                              (k - (sz / 2)) * (k - (sz / 2));
                value = sqrt(value);
                value = max_value * (value / r);
                image[i][j][k] = (short) value;
            }
        }
    }
}

void setToRandomImage(short ***image, short sx, short sy, short sz, short max_value) {
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            for (int k = 0; k < sz; k++) {
                image[i][j][k] = rand() % max_value + 1;
            }
        }
    }
}

short ***getImageMatrix(short sx, short sy, short sz) {
    srand(time(NULL));
    short ***image = new short **[(int) sx];
    for (int i = 0; i < sx; i++) {
        image[i] = new short *[(int) sy];
        for (int j = 0; j < sy; j++) {
            image[i][j] = new short[(int) sz];
        }
    }

    return image;
}


int main() {
    short size = 40;
    short sx = size, sy = size, sz = size, max_value = 20;
    short ***image = getImageMatrix(sx, sy, sz);

    // setToRandomImage(image, sx, sy, sz, max_value);
    setToSphere(image, sx, sy, sz, max_value, size);

    MarchingCube cube(image, sx, sy, sz);
    list <Triangle> triangles = cube.march(10);

    ofstream fout;
    fout.open("triangles.txt");
    fout << triangles.size() << endl;
    for (Triangle triangle : triangles) {
        triangle.print(fout);
    }
    fout.close();

    fout.open("../renderman/triangles.rib");
    for (Triangle triangle : triangles) {
        triangle.render(fout);
    }
    fout.close();
}
