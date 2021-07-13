#ifndef _COMPLEX_
#define _COMPLEX_
#include "quaternion.cpp"

class Complex : public Quaternion {

public:
    // constructor, type cast Quaternion to Complex and type cast Complex to double
    Complex();
    Complex(double re, double im);
    Complex(const Quaternion&);
    operator double() const;
    void printQuaternion() const;
   // Compute norm of complex number, we redefine the norm of Quaternion
    double norm() const;
};

#endif
