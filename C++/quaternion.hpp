#ifndef _QUATERNION_
#define _QUATERNION_
#include <iostream>

class Quaternion {

private:
    double a;
    double b;
    double c;
    double d;

public:
    // Constructors and destructor
    Quaternion();
    Quaternion(double, double, double, double);
    ~Quaternion();
    // Copy constructor and assignment operator
    Quaternion(const Quaternion&);
    Quaternion& operator=(const Quaternion&);

    // Set and get methods
    void setA(double);
    void setB(double);
    void setC(double);
    void setD(double);
    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    // Compute norm of Quaternion
     virtual double norm() const;

     // Work with ostream to print a Quaternion
    virtual void printQuaternion() const;

     // Exercise 12.6
     const Quaternion operator-() const;
     const Quaternion operator~() const;

};
     // Possibility of printing a Quaternion via cout << q
     std::ostream& operator<<(std::ostream& output, const Quaternion& q);
     // Exercise 12.7
     const Quaternion operator+(const Quaternion&, const Quaternion&);
     const Quaternion operator*(const Quaternion&, const Quaternion&);

#endif
