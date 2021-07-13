#include "matrix.hpp"

using namespace std;

Matrix::Matrix(){
    n = 0;
    coeff = (double *) 0;
    cout << "allocate vector, length " << n*n << "\n";
    cout << "Standard constructor: 0-by-0 matrix of type 'F' "<< endl;
}

Matrix::Matrix(int n, char type, double value){
    assert(n>0);
    this->n = n;
    this->type = type;

    if (type == 'F'){
        coeff = (double*) malloc((n*n)*sizeof(double));
        for (int j=0; j<n*n; ++j){
            coeff[j] = value;
        }
        cout << "allocate vector, length " << n*n << " and of type  "<< type <<  "\n";
    }
    else{
        int d = n*(n+1)/2;
        coeff = (double*) malloc(d*sizeof(double));
        for (int j=0; j<d; ++j){
            coeff[j] = value;
		}
		cout << "allocate vector, length " << d << " and of type  "<< type << "\n";
  }
}

Matrix::~Matrix() {
    if (n>0){
        free(coeff);
    }
}

// set matrix dimension
void Matrix::setSize(int k){
    n = k;
}

int Matrix::getSize(){
    return n;
}

// set matrix type
void Matrix::setMatrixType(char character){
    type = character;
}

char Matrix::getMatrixType(){
    return type;
}

void Matrix::setMatrix(int k, double value){
    assert(k >= 0 && k < n*n);
    coeff[k] = value;
}
double Matrix::getMatrix(int k){
    assert(k >= 0 && k < n*n);
    return coeff[k];
}
