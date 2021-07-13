//#include "exercise1.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

double Matrix::columnSumNorm(){
    this->n = n;
    double *x = (double*)malloc(n*sizeof(double));
    double sum = 0;
    double maxi = 0;

    for (int j=0; j<n; j++){
        for (int k=0; k<n; k++){
            sum += abs(coeff[j*n+k]);
        }
        x[j] = sum;
        sum = 0;
    }

    maxi = x[0];
    for (int j = 0; j<n; j++){
        if (maxi < x[j]){
            maxi = x[j];
        }
    }
    return maxi;
}

double Matrix::rowSumNorm(){
    this->n = n;
    double *x = (double*)malloc(n*sizeof(double));
    double sum = 0;
    double maxi = 0;

    for (int j=0; j<n; j++){
        for (int k=0; k<n; k++){
            sum += abs(coeff[j+k*n]);
        }
        x[j] = sum;
        sum = 0;
    }

    maxi = x[0];
    for (int j = 0; j<n; j++){
        if (maxi < x[j]){
            maxi = x[j];
        }
    }
    return maxi;
}

double Matrix::frobeniusNorm(){
    this->n = n;
    double sum = 0;
    for (int i = 0; i < n*n; i++){
      sum += pow(coeff[i], 2.0);
    }
    return sqrt(sum);
}

