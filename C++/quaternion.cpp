#include "quaternion.hpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;
// Constructors and destructor
Quaternion::Quaternion() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;

    //cout << "Standard constructor \n";
}

Quaternion::Quaternion(double a, double b, double c, double d){

    this -> a = a;
    this -> b = b;
    this -> c = c;
    this -> d = d;
}

Quaternion::~Quaternion(){
  //cout << "Destructor is active" << endl;
}

// Assignment operator and copy constructor
Quaternion& Quaternion::operator=(const Quaternion& source) {

    a = source.a;
    b = source.b;
    c = source.c;
    d = source.d;

    // to test if the assignment  works
    //cout<<"Assignment is active" << endl;
    return *this;
}

Quaternion::Quaternion(const Quaternion& rhs){

    a = rhs.a;
    b = rhs.b;
    c = rhs.c;
    d = rhs.d;

    // just to test if it works
    //cout << "Copy constructor is activated" << endl;
}

// Set and get methods
void Quaternion::setA(double w) { a = w; }
void Quaternion::setB(double x) { b = x; }
void Quaternion::setC(double y) { c = y; }
void Quaternion::setD(double z) { d = z; }
double Quaternion::getA() const { return a; }
double Quaternion::getB() const { return b; }
double Quaternion::getC() const { return c; }
double Quaternion::getD() const { return d; }

// Compute norm of Quaternion
double Quaternion::norm() const {
    return a*a + b*b + c*c + d*d;
}

// Work with ostream to print a Quaternion
void Quaternion::printQuaternion() const {
    cout << a << " + " << b << "i" << " + " << c << "j" << " + " << d << "k \n";
}

// Possibility of printing a Quaternion via cout << q
ostream& operator<<(ostream& output, const Quaternion& q) {

    q.printQuaternion();
    return output;
}

// Exercise 12.6
const Quaternion Quaternion::operator-() const{ return Quaternion(-a, -b, -c, -d); }
const Quaternion Quaternion::operator~() const{ return Quaternion(a, -b, -c, -d); }

// Exercise 12.7
const Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {

    Quaternion res;

    res.setA(q1.getA() + q2.getA());
    res.setB(q1.getB() + q2.getB());
    res.setC(q1.getC() + q2.getC());
    res.setD(q1.getD() + q2.getD());

    return res;
}

const Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {

    Quaternion res;

    double a1 = q1.getA();
    double b1 = q1.getB();
    double c1 = q1.getC();
    double d1 = q1.getD();

    double a2 = q2.getA();
    double b2 = q2.getB();
    double c2 = q2.getC();
    double d2 = q2.getD();

    res.setA(a1*a2 - b1*b2 - c1*c2 - d1*d2);
    res.setB(a1*b2 + b1*a2 + c1*d2 - d1*c2);
    res.setC(a1*c2 - b1*d2 + c1*a2 + d1*b2);
    res.setD(a1*d2 + b1*c2 - c1*b2 + d1*a2);

    return res;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------
To show that Hamilton product of two quaternion q1 and q2 is NOT commutative:

Given two Quaternions:
   q1 = a1i + b1j + c1k, q2 = a2i + b2j + c2k;

We compute q1*q2 and q2*q1

   q1*q2 =  a1*a2 - b1*b2 - c1*c2 - d1*d2
           + (a1*b2 + b1*a2 + c1*d2 - d1*c2)i
           + (a1*c2 - b1*d2 + c1*a2 + d1*b2)j
           + (a1*d2 + b1*c2 - c1*b2 + d1*a2)k

   q2*q1 = a2*a1 - b2*b1 - c2*c1 - d2*d1
           + (a2*b1 + b2*a1 + c2*d1 - d2*c1)i
           + (a2*c1 - b2*d1 + c2*a1 + d2*b1)j
           + (a2*d1 + b2*c1 - c2*b1 + d2*a1)k
which is obviously not equal.
--------------------------------------------------------------------------------------------------------------------------------------------------------*/

