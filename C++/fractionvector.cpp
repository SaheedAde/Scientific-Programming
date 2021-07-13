#include "fractionvector.hpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

//standard constructor, empty
FractionVector::FractionVector(){
  n=0;
  vec = (Fraction*) 0;  //null pointer, a vector of zero length
  // just to test
  cout << "Standard constructor, vector of " << n << " length" << endl;
};

// constructor
FractionVector::FractionVector(int n){
    assert(n>=0);
    this->n = n;
    if (n==0){
        vec = (Fraction*)0;
    }
    else{
        vec = new Fraction[n];
        for (int j=0; j<n; ++j){

            vec[j] = Fraction(0,1);
        }
    }
    // just to test if it works
    cout << "Constructor is activated, vector of length  " << n  << endl;
}

// Needed to create a vector of fractions from two arrays,
// one containing the numerators and the other containing the
// denominator.
FractionVector::FractionVector(int a[], int b[], int size) : n(size) {
  vec = new Fraction[n];
  for (int i = 0; i < n; i++) {
    vec[i] = Fraction(a[i], b[i]);
  }
}

// copy constructor
FractionVector::FractionVector(const FractionVector& rhs){
    n = rhs.n;
    vec = new Fraction[n];
    for (int j=0; j<n; ++j){

        vec[j] = rhs[j];
    }
    // just to test if it works
    //cout << "Copy constructor is activated, vector of length " << n << "\n";
}

// assignment operator
FractionVector& FractionVector::operator=(const FractionVector& source) {
  if (n != source.n) {
    delete [] vec;
    n = source.n;
    vec = new Fraction[n];
  }
  for (int i = 0; i < n; i++) {
    vec[i] = source.vec[i];
  }

  // to test if the assignment  works
  cout<<"Assignment is active " << "\n";
  return *this;
}


//destructor
FractionVector::~FractionVector(){
  if(n>=0){
    delete[] vec; // deletes memory
  }
  // to test if the destructor works
  cout<<"Destructor is active, delete memory for the storage of vector of length "<<n<<"\n";
}

// mutator methods
void FractionVector::setLength(int len){
    n = len;
}

int FractionVector::getLength(){
    return n;
}

void FractionVector::setElement(Fraction el, int index){
    assert(index>=0 && index<n);
    vec[index] = el;
}

Fraction FractionVector::getElement(const int& index) const{
    assert(index>=0 && index<n);
    return vec[index];
}

// capability of accessing the vec of the povia [ ]
const Fraction& FractionVector::operator[](int j) const {
    assert(j>=0 && j<n);
    return vec[j];
}

Fraction& FractionVector::operator[](int j) {
    assert(j>=0 && j<n);
    return vec[j];
}

// Possibility of printing a vector
ostream& operator<<(ostream& output, const FractionVector& p) {
  p.print();
  return output;
}

// work with ostream, because we have a vector, we need a for loop
void FractionVector::print() const {
    cout<< "(";
    for (int i=0; i<n-1; i++){
        cout << vec[i] << ", ";
    }
    cout << vec[n-1] << ")" << endl;
}

// Exercise 10.8: sorting the elements of vec through selection sort
void FractionVector::sort(){
    FractionVector  res(*this);
    int j, k, indmin;
    Fraction mintep;

    for (j=0; j<n; j=j+1){
        indmin = j;
        for (k=j+1; k<n; k=k+1){
            if (vec[indmin]>res.vec[k]){
                indmin = k;
            }
        }
        if (indmin>j){
            mintep = res.vec[indmin];
            res.vec[indmin] = res.vec[j];
            res.vec[j] = mintep;
        }
    }
    cout << res << endl;
}

/*-------------------------------------------------------------------------------------
 Computational complexity = O(n^2) for average and worst cases.
 Given n = 10^2 has runtime of T = 0.5 sec:
    -- Computational complexity = O(n^2) => T is proportional to n^2, where T is time
       complexity.
    -- --> T = kn^2 where k is the constant of proportionality.
    -- --> 0.5 = k*100^2, --> k = 0.5/10000, --> T = 0.00005 n^2.
    -- Thus for n = 10^3, we have T =   0.00005(1000)^2 = 50 secs.
--------------------------------------------------------------------------------------*/

