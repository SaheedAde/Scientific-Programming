#include "exercise1.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstdlib>

Matrix::Matrix(int n, char type, double lb, double ub){
    int k = 0;
    assert(n>0);
    this->type = type;
    this->n = n;
    int s;

    if(type == 'F'){
        s = n*n;
    }
    else if(type == 'U' || type =='L'){
        s = n*(n+1)/2;
    }

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(n*n*sizeof(double));
    double* vec = (double*) malloc(s*sizeof(double));
    double rnd;

    for (int i=0; i<s; i++){
        rnd = (ub - lb)*((double)rand() /(double)RAND_MAX) + lb;
        vec[i] = rnd;
    }

    // store the vector into coeff according to the type of Matrix
    if ( type == 'F') {

         for (int i = 0; i < n; ++i){
            for (int j = 0; j<n; ++j , ++k){
                    coeff[i*n + j] = vec[k];
            }
        }
    }
    else if (type == 'L') {

        for (int i = 0; i<n ; i++) {
            for (int j = i; j<n; j++, k++){
               coeff[i*n+j] = vec[k];
               }
            }
    }
        else if (type == 'U'){

            for (int i = 0; i<n; i++){
                for (int j = 0; j<=i; j++, k++){
                        if (j>i){
                             coeff[i*n+j] = 0;
                        }
                        else {
                            coeff[i*n+j] = vec[k];
                        }
                }
           }
        }

     // print the generated matrix
  if(type == 'L'){
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << coeff[i+j*n] << "    ";
            }
           cout << '\n';
        }
    }
    else if(type == 'U'){
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << coeff[i+j*n]<< "    ";
            }
            cout << '\n';
        }
    }

    else{
        for(int i = 0;i < n; i++){
            for(int j = 0 ;j<n;j++){
                cout << "   "<< coeff[i+j*n];
            }
            cout << '\n';
        }
    }
}
