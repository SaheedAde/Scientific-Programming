#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void selectionSort(double* x, int n){
    assert(n>0);
    int j, k, minidx;
    double mintemp;

    for (j=0; j<n; j++){
        minidx = j;
        for (k=j+1; k<n; k++){
            if (x[minidx]>x[k]){
                minidx = k;
            }
        }
        // swap
        if (minidx>j){
            mintemp = x[minidx];
            x[minidx] = x[j];
            x[j] = mintemp;
        }

    }
    for (j=0; j<n; j=j+1){
        printf("%f  ", x[j]);
    }
}

int main() {
    int n, j;
    double* x = NULL;
    printf("Enter the dimension of vector, n:  ");
    scanf("%d", &n);
    x = malloc(n*sizeof(double));
    assert(x!=NULL);
    for (j=0; j<n; j++){
        printf("Enter x[%d] = ", j+1);
        scanf("%lf", &x[j]);
    }

    printf("\nOriginal vector: \n");
    for (j=0; j<n; j=j+1){
        printf("%f  ", x[j]);
    }
    printf("\n\nSorted vector: \n");
    selectionSort(x, n);
    free(x);
    x = NULL;
    return 0;
}

// Computational complexity = O(n^2) for average and worst cases:


