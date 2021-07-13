#ifndef _UPPERTRIANGULARMATRIX_
#define _UPPERTRIANGULARMATRIX_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "vector.hpp"

/*-------------------------------------------------------------------------------------------------------------------------------------------------------
# * Class name: UpperTriangularMatrix
# * Class functionaity: Stores n-by-n upper triangular matrix in  column form
# * n: The dimension of the matrix
# * u: A dynamic vector of length n(n+1)/2
----------------------------------------------------------------------------------------------------------------------------------------------------------*/

class UpperTriangularMatrix{
    // Exercise 11.1
    private:
        int n;
        double* u;

    public:
        // Constructor, destructor, copy constructor and assignment operator
        UpperTriangularMatrix();
        UpperTriangularMatrix(int n, double init = 0);
        UpperTriangularMatrix(int n, double m[]);
        UpperTriangularMatrix(const UpperTriangularMatrix&);
        ~UpperTriangularMatrix();
        UpperTriangularMatrix& operator=(const UpperTriangularMatrix&);

        // Get and set methods
        void setElement(int, int, double)const;
        void setCoeff(int, double)const;
        int getLength() const;
        double getCoeff(int)const;
        double getElement(int, int)const;
        int index(int, int)const;

        // accessing coefficients and scanning a matrix
        //void scanMatrix (int dim) const;
        const double& operator[](int j) const;
        double& operator[](int j);

        // Exercise 11.2
        int size() const;
        const double& operator()( int j, int k) const;
        double& operator() (int j , int k);

        // Exercise 11.3
        // possibility of printing a Matrix, Column sum, Row sum
        void printMatrix() const;
        double columnSumNorm() const;
        double rowSumNorm() const;



};

     std::ostream& operator<<(std::ostream& output, const UpperTriangularMatrix& up);   // Exercise 11.3
     const UpperTriangularMatrix operator+(const UpperTriangularMatrix&, const UpperTriangularMatrix&);   // Exercise 11.4
     const UpperTriangularMatrix operator*(const UpperTriangularMatrix&, const UpperTriangularMatrix&);   // Exercise 11.5
     const Vector operator*(const UpperTriangularMatrix&, const Vector&);   // Exercise 11.6
     const Vector operator|(const UpperTriangularMatrix&, const Vector&);   // Exercise 11.7




#endif // _UPPERTRIANGULARMATRIX_
