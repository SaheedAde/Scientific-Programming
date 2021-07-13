#include "matrix.hpp"
#include "matrix.cpp"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    Matrix matrix;
    matrix.scanMatrix(3, 'F');
    matrix.printMatrix();

    cout << "Column sum norm:  " << matrix.columnSumNorm() << endl;
    cout << "Row sum norm:  " << matrix.rowSumNorm() << endl;
    cout << "Frobenius norm:  " << matrix.frobeniusNorm() << endl;

    return 0;
}
