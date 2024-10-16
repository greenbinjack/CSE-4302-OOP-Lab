#ifndef KELVIN_H
#define KELVIN_H

#include "Celsius.h"
#include "Fahrenheit.h"

class Celsius;
class Fahrenheit;

class Kelvin {
private:
    double temperature;

public:
    Kelvin ();
    Kelvin (double temp);
    ~Kelvin ();

    void assign (double temp);

    void display() const;

    operator Celsius () const;
    operator Fahrenheit () const;
};

#endif // KELVIN_H
