#include "matrix.hpp"
#include "matrix.cpp"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    Matrix matrix;
    matrix.scanMatrix(3, 'F');
    matrix.printMatrix();

    cout << "Trace:  " << matrix.trace() << endl;
    cout << "Is it diagonal? :  " << matrix.isDiagonal() << endl;

    // We test with symmetric matrix A = [1 7 3; 7 4 -5; 3 -5 6]
    cout << "Is it Symmetric? :  " << matrix.isSymmetric() << endl;

    // we test with skew symmetric matrix A = [0 2 -45; -2 0 -4; 45 4 0]
    cout << "Is it Skew Symmetric? :  " << matrix.isSkewSymmetric() << endl;

    return 0;
}
