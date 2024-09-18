#include <bits/stdc++.h>
using namespace std;

class Counter {
private:
    int steps, increment_value;
public:
    void setIncrementStep (int offset) {
        increment_value = offset;
    }
    int getCount () {
        return steps;
    }
    void increment () {
        steps += increment_value;
    }
    void resetCount () {
        steps = 0;
    }
};

int main () {
    Counter c;
    c.resetCount ();
    c.setIncrementStep (3);
    for (int i = 0; i < 5; i++) {
        cout << c.getCount () << endl;
        c.increment ();
    }
    c.setIncrementStep (2);
    c.increment ();

    return 0;
}
