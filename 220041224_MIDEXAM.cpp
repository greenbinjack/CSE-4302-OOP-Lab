#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

class Coordinate {
private:
    float abscissa, ordinate;
public:
    Coordinate () : abscissa (0), ordinate (0) {}
    Coordinate (float x, float y) : abscissa (x), ordinate (y) {}

    void display () {
        cout << "(" << abscissa << ", " << ordinate << ")" << endl;
    }

    void set (float x, float y) {
        abscissa = x;
        ordinate = y;
    }

    float getDistance (Coordinate c) {
        return sqrt ((abscissa - c.abscissa) * (abscissa - c.abscissa) + (ordinate - c.ordinate) * (ordinate - c.ordinate));
    }

    void determineQuadrant () {
        if (abscissa == 0 and ordinate == 0) cout << "Origin" << endl;
        else if (abscissa > 0) cout << ((ordinate > 0) ? "First Quadrant" : "Fourth Quadrant") << endl;
        else cout << ((ordinate > 0) ? "Second Quadrant" : "Third Quadrant") << endl;
    }

    void reflectOverX () {
        ordinate = -ordinate;
    }

    void reflectOverY () {
        abscissa = -abscissa;
    }

    friend Coordinate operator++ (Coordinate &c);
    friend Coordinate operator++ (Coordinate &c, int);
    friend Coordinate operator-- (Coordinate &c);
    friend Coordinate operator-- (Coordinate &c, int);

    ~Coordinate () {}
};

Coordinate operator++ (Coordinate &c) {
    return Coordinate (++c.abscissa, ++c.ordinate);
}

Coordinate operator++ (Coordinate &c, int) {
    return Coordinate (c.abscissa++, c.ordinate++);
}

Coordinate operator-- (Coordinate &c) {
    return Coordinate (--c.abscissa, --c.ordinate);
}

Coordinate operator-- (Coordinate &c, int) {
    return Coordinate (c.abscissa--, c.ordinate--);
}

void sortByLength (Coordinate arr[]) {
    sort (arr, arr + 10, [&] (Coordinate a, Coordinate b) {
        return a.getDistance (Coordinate ()) < b.getDistance (Coordinate());
    });
}

int main () {
    srand (time (nullptr));
    Coordinate arr[10];
    for (int i = 0; i < 10; i++) {
        float x_real = rand () % 100;
        float x_decimal = (1.0 * (rand () % 100)) / 100;
        float x = x_real + x_decimal;

        float y_real = rand () % 100;
        float y_decimal = (1.0 * (rand () % 100)) / 100;
        float y = y_real + y_decimal;
        // cout << fixed << setprecision (2) << x << ' ' << y << endl;
        arr[i].set (x, y);
    }

    cout << "Before Sorting:" << endl;
    for (int i = 0; i < 10; i++) arr[i].display ();

    sortByLength (arr);

    cout << "\nAfter Sorting:" << endl;
    for (int i = 0; i < 10; i++) arr[i].display ();

    arr[9].display ();
    arr[9].reflectOverX ();
    arr[9].display ();
    arr[9].determineQuadrant ();
    Coordinate tmp = arr[9]++;
    tmp.display ();
    arr[9].display ();

    return 0;
}

