#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main () {
    // input
    int a, b, c, d;
    char ch;
    cout << "Enter first fraction: ";
    cin >> a >> ch >> b;
    cout << "Enter second fraction: ";
    cin >> c >> ch >> d;
    // invalid case
    if (!b or !d) {
        cout << "Error: Denominator cannot be 0" << endl;
        exit (0);
    }
    // mathematical operations
    int num = a * d + b * c;
    int denom = b * d;
    int g = __gcd (num, denom);
    if (denom < 0) {
        denom = -denom;
        num = -num;
    }
    // output
    cout << "Sum = " << num / g << '/' << denom / g << endl;
    return 0;
}
