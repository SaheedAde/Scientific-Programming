#include "matrix.hpp"
//#include "exercise1.cpp"    // comment for exercises 3 -- 5

using namespace std;


void Matrix::scanMatrix(int n, char type) {             //this funtion is perfect

std::cout<<"Enter the elements of the matrix in order: "<<std::endl;
this->n = n;
this->type = type;
int k = 0;


    if ( type == 'F') {
        int len = n*n;
        double *vec = (double*)malloc(n*n*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));
        for (int i=0; i<len; i++){
                cin>> vec[i];
        }
         for (int i = 0; i < n; ++i){
            for (int j = 0; j<n; ++j , ++k){
                    coeff[i*n + j] = vec[k];
            }
        }
    }
    else if (type == 'L') {

        int len = n*(n+1)/2;
        double* vec = (double*)malloc(len*sizeof(double));
        coeff = (double*)malloc(n*n*sizeof(double));

        for (int i=0; i<len; i++){
            cin>>vec[i];
        }

        for (int i = 0; i<n ; i++) {
            for (int j = i; j<n; j++, k++){
               coeff[i*n+j] = vec[k];
               }
            }
    }
        else if (type == 'U'){

            int len = n*(n+1)/2;
            double* vec = (double*)malloc(len*sizeof(double));
            coeff = (double*)malloc(n*n*sizeof(double));

            for (int i=0; i<len; i++){
                cin>>vec[i];
            }
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
}

void Matrix::printMatrix(){

    if(type == 'L'){
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << coeff[i+j*n] << "    ";
            }
cout << '\n';
        }
    }else if(type == 'U'){
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << coeff[i+j*n]<< "    ";
            }
            cout << '\n';
                    }
    }else{
        for(int i = 0;i < n; i++){
            for(int j = 0 ;j<n;j++){
                cout << "   "<< coeff[i+j*n];
            }
            cout << '\n';
        }
    }
}
