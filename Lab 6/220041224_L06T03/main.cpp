#include <iostream>
#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

int main() {
    Celsius celsiusTemp(100.0);
    celsiusTemp.display();

    Fahrenheit fahrenheitTemp = celsiusTemp;
    Kelvin kelvinTemp = celsiusTemp;

    fahrenheitTemp.display();
    kelvinTemp.display();

    Kelvin kelvinTemp2(300.0);
    kelvinTemp2.display();

    Celsius celsiusFromKelvin = kelvinTemp2;
    Fahrenheit fahrenheitFromKelvin = kelvinTemp2;

    celsiusFromKelvin.display();
    fahrenheitFromKelvin.display();

    return 0;
}
