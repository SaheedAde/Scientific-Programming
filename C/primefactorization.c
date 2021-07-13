#include <stdio.h>
#include <assert.h>
#include"primefactorization.h"

typedef struct Factorization Factorization;
typedef struct Eratosthenes Eratosthenes;

main(){

    int N;

    printf("Please enter a natural number:   \n");
    scanf("%d", &N);
    assert(N>0);
    Factorization* factorization =  computePrimeFactorization(N);

    int n=factorization->n;
    int* primes = factorization->primes;
    int* multiplicity=factorization->multiplicity;

    printf("The input number %d has the following prime factorization analysis:  \n", N);
    printf("Number of factors = %d \n", n);
    for (int i=0;i<n;i++ ){
          printf("%d is of multiplicity %d \n", primes[i], multiplicity[i] );
    }

    // result of reverse process
    int revResult = recomposeInteger(factorization);
    printf("\nOutput of the recomposed process:   %d \n", revResult);
}
