#include "uppertriangularmatrix.hpp"
#include "uppertriangularmatrix.cpp"
#include <iostream>

using namespace std;

int main() {

    UpperTriangularMatrix U;
    UpperTriangularMatrix U1(3, 3.3);
    UpperTriangularMatrix U2;
    U2 = U1;

    return 0;
}
