#include <iostream>
#include <cmath>
#include "quaternion.cpp"

using std::cout;

int main(){
    Quaternion q1;
    Quaternion q2(1, 2, 3, 4);
    cout << "q2 = " << q2 << "\n";
    cout << "|| q2 ||: " << q2.norm() << "\n";

    return 0;



}

