#include <iostream>
#include "complex.cpp"

using std::cout;

int main(){

    Quaternion q(1, 2, 3, 4);
    Complex c1 = q;

    cout << "--------------------------------------------------------------------------------------------\n";

    cout << "Type cast: Quaternion -> Complex \n";
    cout << "c1 = " << c1 << "\n";

    cout << "--------------------------------------------------------------------------------------------\n";

    double x = c1;
    cout << "Type cast: Complex -> double \n";
    cout << "Re(c1) = " << x << "\n";

    cout << "--------------------------------------------------------------------------------------------\n";

    cout << "Modulus: |c1| = " << c1.norm() << "\n";

    cout << "--------------------------------------------------------------------------------------------\n";

    Complex neg = -c1;
    cout << "Unary operator: -c1 = " << neg << "\n";

    Complex cong = ~c1;
    cout << "Unary operator: ~c1 = " << cong << "\n";

    cout << "--------------------------------------------------------------------------------------------\n";

    Complex c2(5, 6);
    Complex add = c1 + c2;
    cout << "c1 = " << c2 << "\n";
    cout << "Addition: c1 + c2 = " << add << "\n";

    cout << "--------------------------------------------------------------------------------------------\n";

    Complex mult = c1 * c2;
    cout << "c1 = " << c2 << "\n";
    cout << "Multiplication: c1 * c2 = " << mult << "\n";

    return 0;
}


