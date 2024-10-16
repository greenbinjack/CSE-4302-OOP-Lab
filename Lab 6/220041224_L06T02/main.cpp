#include "Coordinate.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void randomAssignment (Coordinate c[], int size){
    ///Write code to assign random abscissa and ordinate to elements of c
    for (int i = 0; i < size; i++) {
        int x = rand () % 10;
        int y = rand () % 10;

        float x_dec = (rand () % 10) / 10.0;
        float y_dec = (rand () % 10) / 10.0;

        float x_coord = x + x_dec;
        float y_coord = y + y_dec;

        c[i].setAbscissa (x_coord);
        c[i].setOrdinate (y_coord);
    }
}

void sort (Coordinate c[], int size){
    for (int i = 0; i < size; i ++) {
        for (int j = i + 1; j < size; j++) {
            if (c[i] > c[j]) swap (c[i], c[j]);
        }
    }
}

void highest (Coordinate c[], int size) {
    cout << "HIGHEST: ";
    c[size - 1].display ();
}

void lowest (Coordinate c[], int size) {
    cout << "LOWEST: ";
    c[0].display ();
}

int main() {
    srand (time (NULL));

    Coordinate c (1.2, 3.5), another;
    c.display ();

    c.move_x (1.2);
    c.display ();

    c.move_y (4.5);
    c.display ();

    c.move (2.5, 4.7);
    c.display ();

    cout << c - another << endl;
    cout << c.getDistance () << endl;

    Coordinate coord[10];
    randomAssignment (coord, 10);
    sort (coord, 10);
    highest (coord, 10);
    lowest (coord, 10);

    return 0;
}
