#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include"primefactorization.h"

typedef struct Factorization Factorization;
// Note that the powerCal function has been defined in primefactorization.h
// function for greatest common divisor
int gcd(int a, int b){
    assert(a>0 && b>0);
    // getting prime factors from computePrimeFactorization function
    // for the first number
    Factorization* aPrimeFact = computePrimeFactorization(a);
    int n_a = aPrimeFact->n;
    int* primes_a = aPrimeFact->primes;
    int* multiplicity_a = aPrimeFact->multiplicity;

    // for the second number
    Factorization* bPrimeFact= computePrimeFactorization(b);
    int n_b = bPrimeFact->n;
    int* primes_b = bPrimeFact->primes;
    int* multiplicity_b = bPrimeFact->multiplicity;

    int GCD = 1;
    int j=0;
    for (int i=0; i<n_a ;i++){
        int Indicator = 0;
        for(j=0; j<n_b; j++){
            if (primes_a[i]==primes_b[j]){
                    Indicator = 1;
                     break;
            }
        }

        int powStr;

        if (Indicator==1){
            if (multiplicity_a[i]<multiplicity_b[j]){

             powStr = powerCal(primes_a[i], multiplicity_a[i]);

            }
            else {

              powStr = powerCal(primes_a[i],multiplicity_b[j]);
            }

         GCD = GCD * powStr;
        }
    }

    return GCD;
}

// function for the LCM
int lcm(int a, int b){
        assert(a>0 && b>0);

        int swapNum, j;
        if (b<a){

            swapNum = b;
            b = a;
            a = swapNum;
    }

       // for the first number
        Factorization* aPrimeFact = computePrimeFactorization(a);
        int n_a = aPrimeFact->n;
        int* primes_a = aPrimeFact->primes;
        int* multiplicity_a = aPrimeFact->multiplicity;

        // for the second number
        Factorization* bPrimeFact= computePrimeFactorization(b);
        int n_b = bPrimeFact->n;
        int* primes_b = bPrimeFact->primes;
        int* multiplicity_b = bPrimeFact->multiplicity;

        int LCM = b;
        for (int i=0; i<n_a ; i++){
        int Indicator = 0;

        for(j=0; j<n_b; j++){
            if (primes_a[i]==primes_b[j]){
                    Indicator = 1;
                    break;
            }
        }
         int powStr = 1;
         if (Indicator==1){
            if (multiplicity_a[i]>multiplicity_b[j]){
             powStr = powerCal(primes_a[i], (multiplicity_a[i]-multiplicity_b[j]));
            }
        }
        else{
            powStr = powerCal(primes_a[i], multiplicity_a[i]);
        }
        LCM = LCM * powStr;
    }
    return LCM;
}

main(){
    int a;
    int b;
    int GCD;
    int LCM;
    printf("Please enter the first natural number, a:  \n");
    scanf("%d",&a);
    printf("Please enter the first natural number, b:  \n");
    scanf("%d",&b);

    GCD = gcd(a , b);
    printf("\ngcd(%d, %d) = %d", a, b, GCD);

    LCM = lcm(a , b);
    printf("\nlcm(%d, %d) = %d\n", a, b, LCM);
}
