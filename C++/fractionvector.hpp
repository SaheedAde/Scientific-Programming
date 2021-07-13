#ifndef _FRACTIONVECTOR_
#define _FRACTIONVECTOR_
#include "fraction.hpp"
#include "fraction.cpp"
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

// a class FractionVector that stores fractions in Q^n
class FractionVector{

    private:
        int n;      // length of the vector
        Fraction* vec;   // define a vector that contains fractions

    public:
        // constructor, destructor, assignment
        FractionVector();
        FractionVector(int n);
        FractionVector(int a[], int b[], int size);
        ~FractionVector();
        FractionVector(const FractionVector&);
        FractionVector& operator=(const FractionVector&);

        // mutator methods
        void setLength(int len);
        int getLength();
        void setElement(Fraction el, int index);
        Fraction getElement(const int& index) const;

        // accessing elements of vector
        const Fraction& operator[](int j) const;
        Fraction& operator[](int j);

        // possibility of printing a vector
        void print() const;
        friend std::ostream& operator<<(std::ostream& output, const FractionVector& p);

        // Exercise 10.8: Sorting
        void sort();
};

#endif
