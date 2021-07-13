#ifndef _FRACTION_
#define _FRACTION_
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

/*------------------------------------------------------------------
A class Fraction that represents fraction in the form x = p/q,
p is an integer, q is a natural number
--------------------------------------------------------------------*/
class Fraction{

    private:
        int p;      // the numerator
        int q;   // the denominator

    public:
        // setter and getter methods
        void setNumerator(int num);
        void setDenominator(int den);
        int getNumerator();
        int getDenominator();

        // standard constructor
        Fraction();
        // constructor
        Fraction(int, int);
        // destructor
        ~Fraction();

        // copy constructor
        Fraction(const Fraction&);
        // assignment operator
        Fraction& operator=(const Fraction&);

        // Ex 10.2 Reduction to lowest terms
        void reduce() const;

        // Ex 10.3 Type casting
        double fracToDouble();
        void doubleToFrac(double x, int n);

        // Ex 10.4 Operator Overloading +, -, *, /
        friend const Fraction operator+(const Fraction& frac1, const Fraction& frac2);
        friend const Fraction operator-(const Fraction& frac1, const Fraction& frac2);
        friend const Fraction operator*(const Fraction& frac1, const Fraction& frac2);
        friend const Fraction operator/(const Fraction& frac1, const Fraction& frac2);

        // Ex 10.5 Overloading - (unary operator)
        const Fraction operator-() const;
        friend std::ostream& operator<<(std::ostream& output, const Fraction& frac);

        // Ex 10.6 Overloading ==, !=, <, <=, >, and >=
        friend bool operator==(const Fraction& frac1, const Fraction& frac2);
        friend bool operator!=(const Fraction& frac1, const Fraction& frac2);
        friend bool operator<(const Fraction& frac1, const Fraction& frac2);
        friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
        friend bool operator>(const Fraction& frac1, const Fraction& frac2);
        friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
};

#endif
