#include "fraction.hpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

// getter and setter methods
void Fraction::setNumerator(int num){
    p = num;
}

void Fraction::setDenominator(int den){
    assert(den != 0);
    q = den;
}

int Fraction::getNumerator(){
    return p;
}

int Fraction::getDenominator(){
    return q;
}

// standard constructor
Fraction::Fraction(){
    p = 0;
    q = 1;
}

// constructor
Fraction::Fraction(int p, int q){
    this -> p = p;
    this -> q = q;
    assert(q!= 0);
    if (q<0){
        setNumerator(-p);
        setDenominator(abs(q));
    }
    else {
        setNumerator(p);
        setDenominator(q);
    }
}

//destructor
Fraction::~Fraction(){
  //cout << "Destructor is active" << endl;
}

// copy constructor
Fraction::Fraction(const Fraction& rhs){
    p = rhs.p;
    q = rhs.q;
    // just to test if it works
    //cout << "Copy constructor is activated" << endl;
}

// assignment operator
Fraction& Fraction::operator=(const Fraction& source) {
    p = source.p;
    q = source.q;
    // to test if the assignment  works
    //cout<<"Assignment is active" << endl;
    return *this;
}

// A non member function that calculates gcd of two numbers
// The use of Recursive Euclidean Algorithm
int gcd(int a, int b) {
	if (!a) return b;
    if (!b) return a;
    if (a==b) return a;
    if (a>b) return gcd(a-b, b);
    return gcd(a, b-a);
}

// Ex 10.2 Reduction to lowest terms
void Fraction::reduce() const{
    if (p<0 || q<0) {
        int a = abs(p);
        int b = abs(q);
        cout << p/gcd(a, b) << "/" << q/gcd(a, b);
    }
    else{
        cout << p/gcd(p, q) << "/" << q/gcd(p, q);
    }
}

// Ex 10.3 Type casting
double Fraction::fracToDouble(){
     return (double)p/q;
}

void Fraction::doubleToFrac(double x, int n){
    assert(n>0 && n<=9);
    Fraction frac;
    frac.p = (int) (pow(10.0, n) * x);
    frac.q = pow(10.0, n);

    frac.reduce();
}

// Ex 10.4 Operator Overloading +, -, *, /
const Fraction operator+(const Fraction& frac1, const Fraction& frac2){
    Fraction result;

    result.p = (frac1.p*frac2.q) + (frac2.p*frac1.q);
    result.q = frac1.q * frac2.q;

    return result;
}

const Fraction operator-(const Fraction& frac1, const Fraction& frac2){
    Fraction result;

    result.p = (frac1.p*frac2.q) - (frac2.p*frac1.q);
    result.q = frac1.q * frac2.q;

    return result;
}

const Fraction operator*(const Fraction& frac1, const Fraction& frac2){
    Fraction result;

    result.p = frac1.p * frac2.p;
    result.q = frac1.q * frac2.q;

    return result;
}

const Fraction operator/(const Fraction& frac1, const Fraction& frac2){
    Fraction result;
    assert(frac2.p != 0);

    result.p = frac1.p * frac2.q;
    result.q = frac1.q * frac2.p;

    return result;
}

// Ex 5 Overloading - (unary operator)
const Fraction Fraction::operator-() const{
    Fraction frac;
    frac.p = -p;
    frac.q = q;

    return frac;
}

// possibility of printing a fraction
std::ostream& operator<<(ostream& output, const Fraction& frac) {
  frac.reduce();
  return output;
}

// Ex 6 Overloading ==, !=, <, <=, >, and >=
bool operator==(const Fraction& frac1, const Fraction& frac2){
	return frac1.p * frac2.q == frac1.q * frac2.p ;
}

bool operator!=(const Fraction& frac1, const Fraction& frac2){
	return frac1.p * frac2.q != frac1.q * frac2.p ;
}

bool operator<(const Fraction& frac1, const Fraction& frac2){
	return frac1.p * frac2.q < frac1.q * frac2.p ;
}

bool operator<=(const Fraction& frac1, const Fraction& frac2){
	return frac1.p * frac2.q <= frac1.q * frac2.p ;
}

bool operator>(const Fraction& frac1, const Fraction& frac2){
	return frac1.p * frac2.q > frac1.q * frac2.p ;
}

bool operator>=(const Fraction& frac1, const Fraction& frac2){
	return frac1.p * frac2.q >= frac1.q * frac2.p ;
}

