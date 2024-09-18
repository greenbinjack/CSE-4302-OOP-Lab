#include <bits/stdc++.h>
using namespace std;

class RationalNumber {
private:
    int num, denom;
public:
    void show_error_message () {
        cout << "You can not assign 0 as denominator" << endl;
    }
    void assign (int numerator, int denominator) {
        if (denominator == 0) {
            show_error_message ();
            return;
        }
        num = numerator;
        denom = denominator;
    }
    double convert () {
        return static_cast <double> (num) / denom;
    }
    void invert () {
        if (num == 0) {
            show_error_message ();
            return;
        }
        swap (num, denom);
    }
    void print () {
        cout << fixed << setprecision (4) << "The Rational Number is " << num << "/" << denom << endl;
    }
};

int main () {
    RationalNumber n;
    n.assign (3, 0);
    n.assign (3, 2);
    n.print ();
    cout << n.convert () << endl;
    n.invert ();
    n.print ();

    return 0;
}
