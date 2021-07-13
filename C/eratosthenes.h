#include<stdlib.h>
#include<stdio.h>

typedef struct Eratosthenes{
    int nmax;
    int n ;
    int* vectorPrimes;
}Eratosthenes;

Eratosthenes* doEratosthenesSieve(int nmax){
    // create a list of numbers from 2 to nmax
    int vecList[nmax+1];
    int m=0;
    while (m<=nmax){
        vecList[m]=m;
        m++;
    }

   for (int j=2; j<=nmax; j=j+1) {
      if(vecList[j]!=0){
         for (int i=2;(j*i)<=nmax; i++){
              vecList[j*i]=0;
        }
    }
}
// store the primes in a dynamic array
    int* eraVec = malloc(1*sizeof(int));
    int dySize = 0;
    for (int k=2; k<=nmax; k++){
        if (vecList[k]!= 0){
            eraVec[dySize] = vecList[k];
            dySize++;
            eraVec = realloc(eraVec, (dySize+1)*sizeof(int));
        }
    }

    // creating an instance of Eratosthenes and storing results there in
    Eratosthenes* primeIns = malloc(sizeof(Eratosthenes));
    primeIns -> nmax =  nmax;
    primeIns -> n = dySize;
    primeIns -> vectorPrimes = eraVec;
    return primeIns;
}
