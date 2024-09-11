#include <iostream>
#include <algorithm>
using namespace std;

struct fraction {
    int num, denom;

    fraction add (const fraction &a) const {
        fraction res;
        res.num = a.num * denom + a.denom * num;
        res.denom = a.denom * denom;
        int g = __gcd (res.num, res.denom);
        res.num /= g, res.denom /= g;
        return res;
    }
};

int main () {
    // input
    fraction a, b;
    char ch;
    cout << "Enter first fraction: ";
    cin >> a.num >> ch >> a.denom;
    cout << "Enter second fraction: ";
    cin >> b.num >> ch >> b.denom;
    // invalid case
    if (!a.denom or !b.denom) {
        cout << "Error: Denominator cannot be 0" << endl;
        exit (0);
    }
    // operation
    fraction result = a.add (b);
    if (result.denom < 0) {
        result.denom = -result.denom;
        result.num = -result.num;
    }
    // output
    cout << "Sum = " << result.num << '/' << result.denom << endl;
    return 0;
}
