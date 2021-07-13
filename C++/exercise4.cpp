#include "exercise1.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

double Matrix::trace(){

    this->n = n;
    double sum = 0;
    for (int i = 0; i < n; i++){
            for (int j=0; j<n; j++){
                if (i==j){
                    sum += coeff[i*n+j];
                }
            }
    }
    return sum;
}

bool Matrix::isDiagonal(){
    int flag = 0;
    this->type = type;

    if(type == 'U' || type=='L'){
           return true;
    }

    else{
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (coeff[i*n+j]==0 && i!=j){
                    flag += 1;
                }
            }
        }
        if (flag == (n*n)-n){          // number of elements in the diagonal = n
            return true;
        }
        else{
            return false;
        }
    }
}


bool Matrix::isSymmetric(){

    int flag = 0;
    this->type = type;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (coeff[i*n+j] != coeff[j*n+i]){
                flag += 1;
            }
        }
    }
    if (flag == 0){          // case when A[i,j] = A[j,i]
        return true;
    }
    else{
        return false;
    }
}


bool Matrix::isSkewSymmetric(){

    int flag = 0;
    this->type = type;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (coeff[i*n+j] != -coeff[j*n+i]){
                flag += 1;
            }
        }
    }
    if (flag == 0){          // case when A[i,j] = -A[j,i]
        return true;
    }
    else{
        return false;
    }
}


