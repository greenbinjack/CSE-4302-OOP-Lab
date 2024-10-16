#include "Coordinate.h"

#include <iostream>
#include <cmath>

using namespace std;

Coordinate :: Coordinate () : abscissa (0.0), ordinate (0.0) {}

Coordinate :: Coordinate (float x, float y) : abscissa (x), ordinate (y) {}

Coordinate :: ~Coordinate() {
    cout << "object has been destroyed" << endl;
}

void Coordinate :: setAbscissa (float x) {
    abscissa = x;
}

void Coordinate :: setOrdinate (float y) {
    ordinate = y;
}

void Coordinate :: display () const {
    cout << "coordinate is (" << abscissa << ", " << ordinate << " )" << endl;
}

float Coordinate :: operator- (const Coordinate &other) const {
    return sqrt ((abscissa - other.abscissa) * (abscissa - other.abscissa) + (ordinate - other.ordinate) * (ordinate - other.ordinate));
}

float Coordinate :: getDistance () const {
    return sqrt (abscissa * abscissa + ordinate * ordinate);
}

void Coordinate :: move_x (float val) {
    abscissa += val;
}

void Coordinate :: move_y (float val) {
    ordinate += val;
}

void Coordinate :: move (float x_val, float y_val) {
    abscissa += x_val;
    ordinate += y_val;
}

bool Coordinate :: operator> (const Coordinate &other) const {
    return this->getDistance() > other.getDistance();
}

bool Coordinate :: operator< (const Coordinate &other) const {
    return this->getDistance() < other.getDistance();
}

bool Coordinate :: operator>= (const Coordinate &other) const {
    return this->getDistance() >= other.getDistance();
}

bool Coordinate :: operator<= (const Coordinate &other) const {
    return this->getDistance() <= other.getDistance();
}

bool Coordinate :: operator== (const Coordinate &other) const {
    return this->getDistance() == other.getDistance();
}

bool Coordinate :: operator!= (const Coordinate &other) const {
    return this->getDistance() != other.getDistance();
}


