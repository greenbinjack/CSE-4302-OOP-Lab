#include "Matrix3D.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector < vector <double> > mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector < vector <double> > mat2 = {
        {4, 4, 4},
        {7, 7, 7},
        {8, 8, 8}
    };

    Matrix3D matrix1 (mat1, 2);
    Matrix3D matrix2 (mat2, 3);

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "Matrix 2:" << endl;
    matrix2.display();

    Matrix3D matrixSum = matrix1 + matrix2;
    Matrix3D matrixDiff = matrix1 - matrix2;
    Matrix3D matrixProd = matrix1 * matrix2;

    cout << "Matrix Sum:" << endl;
    matrixSum.display();

    cout << "Matrix Difference:" << endl;
    matrixDiff.display();

    cout << "Matrix Product:" << endl;
    matrixProd.display();

    if (matrix1 > matrix2) {
        cout << "Matrix1 has a larger determinant than Matrix2." << endl;
    } else {
        cout << "Matrix2 has a larger determinant than Matrix1." << endl;
    }

    return 0;
}
