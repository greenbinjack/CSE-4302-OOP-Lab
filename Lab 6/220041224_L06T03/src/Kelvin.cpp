#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>

using namespace std;

Kelvin :: Kelvin () : temperature (273.15) {}

Kelvin :: Kelvin (double temp) {
    assign(temp);
}

void Kelvin :: assign (double temp) {
    temperature = (temp >= 0.0) ? temp : 0.0;  // Limit to absolute zero
}

Kelvin :: ~Kelvin () {
    cout << "object has been destroyed." << endl;
}

void Kelvin :: display() const {
    cout << "The temperature is " << temperature << " Kelvin." << endl;
}

Kelvin :: operator Celsius () const {
    return Celsius (temperature - 273.15);
}

Kelvin :: operator Fahrenheit() const {
    return Fahrenheit ((temperature - 273.15) * 9.0 / 5.0 + 32);
}
