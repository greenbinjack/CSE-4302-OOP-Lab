#ifndef MATRIX3D_H
#define MATRIX3D_H

#include <iostream>
#include <vector>

using namespace std;

const int DIMENSION = 3;

class Matrix3D {
private:
    vector < vector<double> > matrix;
    int incrementValue;
    int count;

public:
    Matrix3D (const vector < vector<double> > &matrix, int inc = 1);

    ~Matrix3D();

    double det() const;

    Matrix3D inverse() const;

    void setIncrement (int val);

    vector < vector<double> > getMatrix() const;

    void increment();

    Matrix3D operator+ (const Matrix3D &other) const;
    Matrix3D operator- (const Matrix3D &other) const;
    Matrix3D operator* (const Matrix3D &other) const;

    bool operator> (const Matrix3D &other) const;
    bool operator< (const Matrix3D &other) const;
    bool operator>= (const Matrix3D &other) const;
    bool operator<= (const Matrix3D &other) const;
    bool operator== (const Matrix3D &other) const;
    bool operator!= (const Matrix3D &other) const;

    void display() const;
};

#endif
