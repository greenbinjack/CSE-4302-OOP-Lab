#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>

using namespace std;

Celsius :: Celsius() : temperature (0.0) {}

Celsius :: Celsius (double temp) {
    assign(temp);
}

Celsius :: ~Celsius () {
    cout << "object has been destroyed." << endl;
}

void Celsius :: assign (double temp) {
    temperature = (temp >= -273.15) ? temp : -273.15;  // Limit to absolute zero
}

void Celsius::display() const {
    cout << "The temperature is " << temperature << " Celsius." << endl;
}

Celsius :: operator Fahrenheit () const {
    return Fahrenheit (temperature * 9.0 / 5.0 + 32);
}

Celsius :: operator Kelvin () const {
    return Kelvin (temperature + 273.15);
}
