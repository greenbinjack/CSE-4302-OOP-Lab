#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>  // For NaN
using namespace std;

class Calculator {
private:
    double angle;
    double getAngle () {
        return angle;
    }
    void setAngle (double _angle) {
        angle = _angle;
    }
    void warning () {
        cout << "Invalid operation: undefined result." << endl;
    }
public:
    Calculator () : angle (0.0) {}
    Calculator (double _angle) : angle (_angle) {}
    double degreeToRadian (double _angle) {
        return _angle * acos (-1.0) / 180.0;
    }
    void printRadian (double _angle) const {
        cout << "Radian angle: " << _angle << endl;
    }
    double calculateSine () {
        return sin (degreeToRadian (getAngle ()));
    }
    double calculateCosine () {
        return cos (degreeToRadian (getAngle()));
    }
    double calculateTangent () {
        double current_angle = fmod (getAngle(), 180);  // To handle odd pi/2
        if (current_angle == 90 || current_angle == -90) {
            warning ();
            return numeric_limits <double> :: quiet_NaN();  // Return NaN for undefined tangent
        }
        return tan (degreeToRadian (getAngle()));
    }
    double calculateArcSine() {
        double sine_value = calculateSine ();
        printRadian (asin (sine_value));
        return asin (sine_value);
    }
    double calculateArcCosine() {
        double cosine_value = calculateCosine();
        printRadian (acos (cosine_value));
        return acos (cosine_value);
    }
    double calculateArcTangent() {
        double tangent_value = calculateTangent();
        if (!isnan (tangent_value)) {
            printRadian (atan (tangent_value));
            return atan(tangent_value);
        }
        return tangent_value;  // Return NaN if tangent was undefined
    }
    void calculateForAngle (double paramAngle) {
        cout << "For angle " << paramAngle << " degrees:" << endl;
        cout << "Sine = " << sin(degreeToRadian (paramAngle)) << endl;
        cout << "Cosine = " << cos(degreeToRadian (paramAngle)) << endl;

        double paramTangent = tan(degreeToRadian (paramAngle));
        if (fmod (paramAngle, 180) == 90 || fmod (paramAngle, 180) == -90) {
            warning();
        } else {
            cout << "Tangent = " << paramTangent << endl;
        }
    }
    void clear () {
        setAngle (0.0);
    }
    void display () {
        cout << "Calculator display: " << getAngle () << endl;
    }
    ~Calculator () {
        display ();
        cout << "Destructor of the Calculator object is called." << endl;
    }
};

int main () {
    Calculator c1, c2 (54);
    cout << "Sin " << c2.calculateSine () << endl;
    cout << "Cos " << c2.calculateCosine () << endl;
    cout << "Tan " << c2.calculateTangent () << endl;
    cout << "Arcsin " << c2.calculateArcSine () << endl;
    cout << "Arccos " << c2.calculateArcCosine () << endl;
    cout << "Arctan " << c2.calculateArcTangent () << endl;
    return 0;
}
