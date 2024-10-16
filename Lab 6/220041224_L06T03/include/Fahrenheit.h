#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

#include "Celsius.h"
#include "Kelvin.h"

class Celsius;
class Kelvin;

class Fahrenheit {
private:
    double temperature;

public:
    Fahrenheit();
    Fahrenheit (double temp);
    ~Fahrenheit ();

    void assign (double temp);

    void display () const;

    operator Celsius () const;
    operator Kelvin () const;
};

#endif // FAHRENHEIT_H
