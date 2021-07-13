#include "complex.hpp"
#include <iostream>
#include <cmath>

using std::cout;

Complex::Complex(){
    cout << "Complex constructor \n";
}

Complex::Complex(double re, double im) : Quaternion(re, im, 0, 0){
    cout << "Complex constructor \n";

}

Complex::Complex(const Quaternion& rhs) : Quaternion(rhs.getA(), rhs.getB(), 0, 0){
   (*this).setA(rhs.getA());
   (*this).setB(rhs.getB());
}

Complex::operator double() const{
    return getA();
}

// Redefinition of printQuaternion to adapt it to print Complex
void Complex::printQuaternion() const {
    cout << getA() << " + " << getB() << "*i";
}
// Redefinition of norm to adapt to Complex objects
double Complex::norm() const {
    return sqrt(getA()*getA() + getB()*getB());

}
