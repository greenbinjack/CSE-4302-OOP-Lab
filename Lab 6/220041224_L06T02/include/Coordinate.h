#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

using namespace std;

class Coordinate {
private:
    float abscissa, ordinate;
public:
    Coordinate ();
    Coordinate (float x, float y);
    ~Coordinate();

    void setAbscissa (float x);
    void setOrdinate (float y);

    void display () const;

    float operator - (const Coordinate &other) const;

    float getDistance () const;
    void move_x (float val);
    void move_y (float val);
    void move (float x_val, float y_val);

    bool operator> (const Coordinate &other) const;
    bool operator< (const Coordinate &other) const;
    bool operator>= (const Coordinate &other) const;
    bool operator<= (const Coordinate &other) const;
    bool operator== (const Coordinate &other) const;
    bool operator!= (const Coordinate &other) const;
};

#endif // COORDINATE_H
