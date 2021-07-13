#include "vector.hpp"
#include "vector.cpp"
#include <iostream>
using std::cout;

int main() {
    Vector vector1;
    Vector vector2(100,4);
    Vector vector3 = 4*vector2;
    cout << "*** Addition\n";
    vector1 = vector2 + vector2;
    cout << "Norm1 = " << vector1.norm() << "\n";
    cout << "Norm2 = " << vector2.norm() << "\n";
    cout << "Norm3 = " << vector3.norm() << "\n";
    cout << "Skalarprodukt = " << vector2*vector3 << "\n";
    cout << "Norm " << (4*vector3).norm() << "\n";
    return 0;
}
