#include "matrix.hpp"
#include "matrix.cpp"
#include <iostream>

using namespace std;

int main() {

    Matrix matrix;

    matrix.scanMatrix(3, 'F');
    matrix.printMatrix();

    return 0;
}
