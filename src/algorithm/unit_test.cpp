//
// Created by Bijoy Kochar on 3/27/16.
//

#include "Point.h"
#include "EdgeTable.h"
#include "MarchingCube.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

short ***getRandomImage(short sx, short sy, short sz, short max_value) {
    srand(time(NULL));
    short ***image = new short **[(int) sx];
    for (int i = 0; i < sx; i++) {
        image[i] = new short *[(int) sy];
        for (int j = 0; j < sy; j++) {
            image[i][j] = new short[(int) sz];
            for (int k = 0; k < sz; k++) {
                image[i][j][k] = rand() % max_value + 1;
            }
        }
    }

    return image;
}


int main() {
    short size = 3;
    short sx = size, sy = size, sz = size, max_value = 10;
    short ***image = getRandomImage(sx, sy, sz, max_value);
    MarchingCube cube(image, sx, sy, sz);
    list <Triangle> triangles = cube.march(5);

    ofstream fout;
    fout.open("triangles.txt");
    fout << triangles.size() << endl;
    for (Triangle triangle : triangles) {
        triangle.print(fout);
    }
    fout.close();
}
