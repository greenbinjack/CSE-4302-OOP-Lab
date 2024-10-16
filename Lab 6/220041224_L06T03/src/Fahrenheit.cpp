#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>

using namespace std;

Fahrenheit :: Fahrenheit() : temperature (32.0) {}

Fahrenheit :: Fahrenheit (double temp) {
    assign (temp);
}

Fahrenheit :: ~Fahrenheit () {
    cout << "object has been destroyed." << endl;
}

void Fahrenheit :: assign (double temp) {
    temperature = (temp >= -459.67) ? temp : -459.67;  // Limit to absolute zero
}

void Fahrenheit :: display() const {
    cout << "The temperature is " << temperature << " Fahrenheit." << endl;
}

Fahrenheit :: operator Celsius () const {
    return Celsius ((temperature - 32) * 5.0 / 9.0);
}

Fahrenheit :: operator Kelvin () const {
    return Kelvin ((temperature - 32) * 5.0 / 9.0 + 273.15);
}
