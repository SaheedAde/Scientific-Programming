#include <stdio.h>
#include <math.h>
#include <assert.h>
#include"eratosthenes.h"

typedef struct Eratosthenes Eratosthenes;

main(){

    int nmax;
    printf("Please enter a natural number:  \n");
    scanf("%d",&nmax);
    assert(nmax>0);

    // extracting the stored values in Eratosthenes
    Eratosthenes* erasResult = doEratosthenesSieve(nmax) ;
    int erasNum = erasResult -> n;
    int* erasArr = erasResult -> vectorPrimes;


    printf("The prime numbers for the input  number %d are:   \n ", nmax);
    int i;
    for (i=0; i<erasNum; i++){
            printf("%d \n ", erasArr[i]);
        }

}

