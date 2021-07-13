#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Eratosthenes.h"

typedef struct Factorization{
 int n;
 int* primes;
 int* multiplicity;
} Factorization;

typedef struct Eratosthenes Eratosthenes;


Factorization* computePrimeFactorization(int N){
// eratIns inherits the properties of Eratosthenes
Eratosthenes* eratIns =  doEratosthenesSieve(N);

    int* vecPrimes = eratIns->vectorPrimes;
    int n = eratIns->n;
    int* vecFact = malloc(1 * sizeof(int));  // initialize array to store factors
    int* multiplicity = malloc(1 * sizeof(int));

    int factCounter=0;   // initialize counter for factors
    int multCounter=0;   // initialize counter for multiplicity

    for(int i=0;i<n;i++) {
           if((N % vecPrimes[i]) == 0){
                vecFact[factCounter]=vecPrimes[i];
                multCounter=0;

                while ((N % vecPrimes[i]) == 0){
                    multCounter++;
                    N=N/vecPrimes[i];       // continuously dividing by each prime to get their multiplicity
                }
                multiplicity[factCounter] = multCounter;
                factCounter++;
                vecFact = realloc(vecFact, (factCounter+1) * sizeof(int));    // dynamically changing the size of arr
                multiplicity = realloc(multiplicity, (factCounter+1) * sizeof(int));   // dynamically changing the size of arr

            }
            if (N==0) break;    // stops when N reduces to 0.
    }
    // make an inheritor of Factorization to store values
    Factorization* facInherit = malloc(sizeof(Factorization));
    facInherit->n = factCounter;
    facInherit->primes = vecFact;
    facInherit->multiplicity = multiplicity;
    return facInherit;
}

int powerCal(int base, int power){

    for(int i=1;i<power; i++){
        base = base * base;
    }
    return base;
}
// function to carry out the reverse of the of the above process, i.e to compute N from its prime factors
// and their multiplicities
int recomposeInteger(Factorization* factorization){
    int newNum = factorization->n;
    int* newPrime = factorization->primes;
    int* newMul =factorization->multiplicity;

    int N=1;
        for (int i=0;i<newNum; i++ ){
           N=N * powerCal(newPrime[i],newMul[i]);
        }
    return N;
}

