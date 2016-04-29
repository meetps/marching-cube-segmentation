//
// Created by Bijoy Kochar on 3/27/16.
//

#include "Point.h"
#include "EdgeTable.h"
#include "MarchingCube.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    MarchingCube cube("../../data/VSD.Brain.XX.O.MR_Flair/Flair.csv");
    list <Triangle> triangles = cube.march(1050);

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

    string cmd;
    int count = 0;

    cmd = "cd ../renderman; make individual AX=" + to_string(60)
          + " AY=" + to_string(60)
          + " AZ=" + to_string(60)
          + " FILENAME=" + to_string(count);
    const char *cmd_car = cmd.c_str();
    system(cmd_car);
    cout << cmd << endl;
    count++;

    for (int a = -90; a <= 90; a += 15) {
        cmd = "cd ../renderman; make individual AX=" + to_string(a)
              + " AY=" + to_string(a)
              + " AZ=" + to_string(a)
              + " FILENAME=" + to_string(count);
        const char *cmd_car = cmd.c_str();
        system(cmd_car);
        cout << cmd << endl;
        count++;
    }

    for (int a = -90; a <= 90; a += 15) {
        cmd = "cd ../renderman; make individual AX=" + to_string(0)
              + " AY=" + to_string(a)
              + " AZ=" + to_string(0)
              + " FILENAME=" + to_string(count);
        const char *cmd_car = cmd.c_str();
        system(cmd_car);
        cout << cmd << endl;
        count++;
    }

    for (int a = -90; a <= 90; a += 15) {
        cmd = "cd ../renderman; make individual AX=" + to_string(0)
              + " AY=" + to_string(0)
              + " AZ=" + to_string(a)
              + " FILENAME=" + to_string(count);
        const char *cmd_car = cmd.c_str();
        system(cmd_car);
        cout << cmd << endl;
        count++;
    }

    for (int a = -90; a <= 90; a += 15) {
        cmd = "cd ../renderman; make individual AX=" + to_string(a)
              + " AY=" + to_string(0)
              + " AZ=" + to_string(0)
              + " FILENAME=" + to_string(count);
        const char *cmd_car = cmd.c_str();
        system(cmd_car);
        cout << cmd << endl;
        count++;
    }
}