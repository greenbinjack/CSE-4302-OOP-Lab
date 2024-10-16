#ifndef CELSIUS_H
#define CELSIUS_H

#include "Fahrenheit.h"
#include "Kelvin.h"

class Kelvin;
class Fahrenheit;

class Celsius {
private:
    double temperature;

public:
    Celsius();
    Celsius (double temp);
    ~Celsius ();

    void assign (double temp);

    void display() const;

    operator Fahrenheit() const;
    operator Kelvin() const;
};

#endif // CELSIUS_H
