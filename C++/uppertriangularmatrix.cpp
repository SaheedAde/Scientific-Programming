#include "uppertriangularmatrix.hpp"
#include "vector.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;
// Exercise 11.1
/*----------------------------------------------------------------------------------------------------------------------------------------------------
The derived formula for the index l(j,k) = ((k+1)*k/2) + j where j denotes the row and k denotes the column.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
UpperTriangularMatrix::UpperTriangularMatrix() {
    n = 0;
    u = (double*) 0;
    // just for demonstration purposes
    cout << "constructor, empty\n";
}

UpperTriangularMatrix::UpperTriangularMatrix(int n, double init) {
    assert(n >= 0);
    this->n = n;
    if (n == 0) {
       u = (double*) 0;
    }
    else {
          u = new double[getLength()];
          for (int j=0; j<getLength(); ++j) {
               u[j] = init;
          }
    }
    // just for demonstration purposes
    cout << "constructor, length " << getLength() << "\n";
}

UpperTriangularMatrix::UpperTriangularMatrix(int n, double m[]) {
    assert(n >= 0);
    this->n = n;
    if (n == 0) {
       u = (double*) 0;
    }
    else {
          u = new double[getLength()];
          for (int j=0; j<getLength(); ++j) {
               u[j] = m[j];
          }
    }
    // just for demonstration purposes
    cout << "constructor, length " << getLength() << "\n";
}

UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix& rhs) {
    n = rhs.n;
    if (n == 0) {
         u = (double*) 0;
    }
    else {
        u = new double[getLength()];
        for (int j=0; j<getLength(); ++j) {
               u[j] = rhs[j];
        }
    }
    // just for demonstration purposes
    cout << "copy constructor, length " << getLength() << "\n";
}

UpperTriangularMatrix::~UpperTriangularMatrix() {
    if (n > 0) {
         delete[] u;
    }
    // just for demonstration purposes
    cout << "free vector, length " << getLength() << "\n";
}

UpperTriangularMatrix& UpperTriangularMatrix::operator=(const UpperTriangularMatrix& rhs) {
    int dim = getLength();
    if (this != &rhs) {

         if (dim != rhs.getLength()) {

                if (dim > 0) {

                    delete[] u;
                 }
         dim = rhs.getLength();
         if (dim > 0) {

             u = new double[dim];
         }
        else {
             u = (double*) 0;
        }
      }
     for (int j=0; j<dim; ++j) {

            u[j] = rhs[j];
     }
 }
     // just for demonstration purposes
     cout << "deep copy, length " << dim << "\n";
     return *this;
}

int UpperTriangularMatrix::index(int i, int j)const{
    //return n*i - (i*(i-1)/2) + j-i;
    return ((j+1)*j/2) + i ;
}
void UpperTriangularMatrix::setElement(int i, int j, double value)const{
        assert(index(i,j)<n*(n+1)/2);
        u[index(i,j)] = value;
}

void UpperTriangularMatrix::setCoeff(int i, double value)const{
        assert(i<n*(n+1)/2);
        u[i] = value;
}

int UpperTriangularMatrix::getLength() const{return n*(n+1)/2;}

double UpperTriangularMatrix::getCoeff(int i) const{return u[i];}

double UpperTriangularMatrix::getElement(int i, int j)const{

    assert(index(i,j)<n*(n+1)/2);
    return *(u+index(i,j));
}

// Exercise 11.2
int UpperTriangularMatrix::size() const {
      return n;
}

// capability of accessing the coeff of the Matrix via ()
const double& UpperTriangularMatrix::operator()( int j, int k) const{
    assert(j>=0 && j<=n-1 && k>=0 && k<=n-1 );
    if (k<j){
          return 0.0; // setElement(j, k, 0);
    }
    return *(u+index(j,k));
}

double& UpperTriangularMatrix::operator() (int j , int k) {
    assert(j>=0 && j<=n-1 && k>=0 && k<=n-1 );
    if (k<j){
         return 0.0; //setElement(j, k, 0);
    }
    return *(u+index(j,k));
}

const double& UpperTriangularMatrix::operator[](int j) const {
    assert(j>=0 && j<n*(n+1)/2);
    return u[j];
}

double& UpperTriangularMatrix::operator[](int j) {
    assert(j>=0 && j<n*(n+1)/2);
    return u[j];
}

// Exercise 11.3
void UpperTriangularMatrix::printMatrix() const{

    for (int i=0; i<size(); i++){

        for (int j=0; j<size(); j++){

            if (j>=i){
            cout << getElement(i,j) << "  ";
            }
            else {
                cout << "0" << "  ";
            }
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& output, const UpperTriangularMatrix& up) {
  up.printMatrix();
  return output;
}

double UpperTriangularMatrix::columnSumNorm() const{

    double result = 0;
    for (int j=0; j<size(); j++){
           double sum=0;
            for (int i=0; i<size(); i++){

                if (j>=i){
                    sum = sum + fabs(getElement(i,j));
                }
            }
            if( sum >= result ){ result = sum;}
        }

        return result;
}

double UpperTriangularMatrix::rowSumNorm() const{

    double result = 0;
    for (int i=0; i<size(); i++){

       double sum=0;
        for (int j=1; j<size(); j++){

            if (j>=i){

                sum=sum+fabs(getElement(i,j));

            }
        }

        if(sum>=result){result=sum;}
    }

    return result;
}

// Exercise 11.4
const UpperTriangularMatrix operator+(const UpperTriangularMatrix& U1, const UpperTriangularMatrix& U2){

    assert(U1.size() == U2.size());
    UpperTriangularMatrix result(U1);

    for (int i=0; i<U1.getLength(); ++i){
            result[i] += U2[i];
    }


    return result;
}

// Exercise 11.5
/*-----------------------------------------------------------------------------------------------------------------------------------------------------
Given the product of two upper triangular matrices A and B as C_ij = \sum A_ik B_kj from k=0 to n-1. To show that C is upper triangular, we need to show
that if i>j then C_ij evaluates to 0.

To this end, we consider two cases and suppose i>j:

   -i. If i>k then A_ik = 0 since A is an upper triangular matrix. Hence A_ik B_kj = 0.
   -ii. If k>j then B_kj = 0 since B is an upper triangular matrix. Hence A_ik B_kj = 0.

   Since i>j, for every k we either have i>k or k>j (possibly both) so these two cases cover all possibilities for k.

--------------------------------------------------------------------------------------------------------------------------------------------------------*/

const UpperTriangularMatrix operator*(const UpperTriangularMatrix& U1, const UpperTriangularMatrix& U2){

    assert(U1.size() == U2.size());
    UpperTriangularMatrix result(U1.size());

    for (int i=0; i<U1.size(); ++i){

            for (int j=0; j<U1.size(); ++j){

                    double sum = 0;

                  for (int k=0; k<U1.size(); ++k){

                        if (i<=k && k<=j){

                             sum = sum + U1.getElement(i,k)*U2.getElement(k,j);
                             result.setElement(i,j, sum);
                        }


                  }

            }
    }

    return result;
}

// Exercise 11.6
const Vector operator*(const UpperTriangularMatrix& U, const Vector& x){
    assert(U.size() == x.size());
    Vector result(x.size());

    for (int j=0; j<x.size(); ++j){

        double sum = 0;

        for (int k=0; k<x.size(); ++k){

            if (j<=k){

                sum = sum + (U.getElement(j,k)*x.getEntry(k));
                result.setEntry(j, sum);

            }
        }
    }
    return result;
}

// Exercise 11.7
/*----------------------------------------------------------------------------------------------------------------------------------------------------
Given the linear system Ux = b, where U is an upper triangular matrix, x is an unknown vector, and b is a column vector. Such a system can be written
as:
      u_ii x_i + u_{i,i+1} x_{i+1} + ... + u_{in} x_n = b_i

for i = 1,2,...,n.

The solution for the vector x is thus given by

      x_i = (b_i - \sum u_ij x_j from j = i+1 to n) / u_ii

for i = n, ..., 1 (backward substitution).
-------------------------------------------------------------------------------------------------------------------------------------------------------*/

const Vector operator|(const UpperTriangularMatrix& U, const Vector& b){

    assert(U.size() == b.size());
    Vector result(b.size());

    for (int i=b.size()-1; i>=0; i--){

        double s = 0;

        for (int j=i+1; j<b.size(); ++j){

                s = s + U.getElement(i,j)*result[j];
        }

        assert(U.getElement(i, i) != 0);
        result[i] = (b[i]-s)/U.getElement(i,i);
    }
    return result;
}

// Exercise 11.8
/*---------------------------------------------------------------------------------------------------------------------------------------------------
1. COMPUTATIONAL COMPLEXITY OF Ex 11.5:
    - We have two assignments enclosed in the last for-loop, thus summing over the three loops we have that the time complexity is O(n^3).
    - Given n=10^3 with a runtime of 2 sec, then for n=5*10^3 we have:
          t = 2*(5*10^3)^3/(10^3)^3 = 250 sec.

2. COMPUTATIONAL COMPLEXITY OF Ex 11.6:
   - We have two assignments enclosed in the second for-loop, thus summing the two loops gives a time complexity of O(n^2):
   - Given n=10^3 with a runtime of 2 sec, then for n=5*10^3 we have:
          t = 2*(5*10^3)^2/(10^3)^2 = 50 sec.

3. COMPUTATIONAL COMPLEXITY OF Ex 11.7:
   - We have 1 assignment enclosed in two for-loop and another 1 assignment enclosed in one loop, summing over the loops gives
     complexity of O(n^2).
    - Thus given n=10^3 with a runtime of 2 sec, then for n=5*10^3 we have:
          t = 2*(5*10^3)^2/(10^3)^2 = 50 sec.
------------------------------------------------------------------------------------------------------------------------------------------------------*/



