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

    for (int i = 0; i < sz; i++) {
        for (int j = sy - 1; j >= 0 ; j--) {
            for (int k = 0; k < sx; k++) {
                cout << image[k][j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return image;
}

int main() {
    short sx = 2, sy = 2, sz = 2, max_value = 4;
    short ***image = getRandomImage(sx, sy, sz, max_value);
    MarchingCube cube(image, sx, sy, sz);
    cube.march(2);
}
