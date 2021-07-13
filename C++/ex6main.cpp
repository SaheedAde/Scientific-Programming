#include <iostream>
#include <cmath>
#include "quaternion.cpp"

using std::cout;

int main(){

    Quaternion q(1, 2, 3, 4);
    cout << "-q = " << -q << "\n";
    cout << "~q = " << ~q << "\n";

    return 0;
}

