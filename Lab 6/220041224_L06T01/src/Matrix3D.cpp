#include "Matrix3D.h"
#include <iostream>
#include <vector>

using namespace std;

Matrix3D :: Matrix3D (const vector < vector<double> > &mat, int inc) : matrix (mat), count(0) {
    incrementValue = (inc > 0) ? inc : 1;
}

Matrix3D :: ~Matrix3D() {
    cout << "object has been destroyed." << endl;
}

double Matrix3D :: det() const {
    double a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    double d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    double g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];

    double determinant = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);

    return determinant;
}

Matrix3D Matrix3D :: inverse() const {
    double determinant = det ();
    if (determinant == 0) {
        cout << "Matrix is singular, inverse does not exist." << endl;
        return *this;
    }

    double a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    double d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    double g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];

    double A11 = (e * i - f * h);
    double A12 = -(d * i - f * g);
    double A13 = (d * h - e * g);
    double A21 = -(b * i - c * h);
    double A22 = (a * i - c * g);
    double A23 = -(a * h - b * g);
    double A31 = (b * f - c * e);
    double A32 = -(a * f - c * d);
    double A33 = (a * e - b * d);

    vector< vector <double> > cofactorMatrix = {
        {A11, A12, A13},
        {A21, A22, A23},
        {A31, A32, A33}
    };

    vector< vector<double> > adjugateMatrix (DIMENSION, vector <double> (DIMENSION));
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            adjugateMatrix[i][j] = cofactorMatrix[j][i] / determinant;
        }
    }

    return adjugateMatrix;
}

void Matrix3D :: setIncrement (int val) {
    if (count == 0) {
        if (val > 0) incrementValue = val; // Increment value set to incrementValue
        else cout << "Negative value not allowed. Increment value remains " << incrementValue << endl;
    } else cout << "Cannot set increment value, count is not 0." << endl;
}

vector < vector<double> > Matrix3D :: getMatrix() const {
    return matrix;
}

void Matrix3D :: increment() {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            matrix[i][j] += incrementValue;
        }
    }
    count++;
}

Matrix3D Matrix3D :: operator+ (const Matrix3D &other) const {
    Matrix3D result = *this;
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            result.matrix[i][j] += other.matrix[i][j];
        }
    }
    return result;
}

Matrix3D Matrix3D :: operator- (const Matrix3D &other) const {
    Matrix3D result = *this;
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            result.matrix[i][j] -= other.matrix[i][j];
        }
    }
    return result;
}

Matrix3D Matrix3D :: operator* (const Matrix3D &other) const {
    Matrix3D result = *this;
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            result.matrix[i][j] *= other.matrix[i][j];
        }
    }
    return result;
}

bool Matrix3D :: operator> (const Matrix3D &other) const {
    return this->det() > other.det();
}

bool Matrix3D :: operator< (const Matrix3D &other) const {
    return this->det() < other.det();
}

bool Matrix3D :: operator>= (const Matrix3D &other) const {
    return this->det() >= other.det();
}

bool Matrix3D :: operator<= (const Matrix3D &other) const {
    return this->det() <= other.det();
}

bool Matrix3D :: operator== (const Matrix3D &other) const {
    return this->det() == other.det();
}

bool Matrix3D :: operator!= (const Matrix3D &other) const {
    return this->det() != other.det();
}

void Matrix3D :: display() const {
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            cout << matrix[i][j] << " \n"[j == DIMENSION - 1];
        }
    }
}
