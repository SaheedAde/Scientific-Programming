#include <iostream>
#include <cmath>
#include "quaternion.cpp"

using std::cout;

int main(){

    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    cout << "q1 + q2 = " << q1 + q2 << "\n";
    cout << "q1 * q2 = " << q1 * q2 << "\n";
    cout << "q2 * q1 = " << q2 * q1 << "\n";

    return 0;
}

