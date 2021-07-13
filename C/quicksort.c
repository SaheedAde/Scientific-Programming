#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// partition the given array into two subarrays and returns the final index of pivot
int partitionArr(double* x, int sIndex, int eIndex){
    int i;
    double pElmt;
    double cElmt;
    int pivot = x[eIndex];    // set pivot as element
    int pIndex = sIndex; // set partition index as start initially

    for (i=sIndex; i<eIndex; i++){
        if (x[i]<=pivot){
            cElmt = x[i];
            x[i] = x[pIndex];
            x[pIndex] = cElmt;
            pIndex++;
        }
    }
    pElmt = x[pIndex];
    x[pIndex] = x[eIndex];
    x[eIndex] = pElmt;
    return pIndex;
}

// Helper function to handle the recursive
double* quickHelper(double* x, int sIndex, int eIndex){

    int pIndex;
    if(sIndex<eIndex){
        pIndex = partitionArr(x, sIndex, eIndex);
        quickHelper(x, sIndex,  pIndex-1);
        quickHelper(x, pIndex+1, eIndex);
    }
    return x;
}

// main function quickSort calling the helper functions
// pIndex = pivot index
// sIndex = fist index
// eIndex = last index
void quickSort(double* x, int n){
    assert(n>0);
    int i;
    int sIndex = 0;
    int eIndex = n-1;
    double *v = NULL;
    v = malloc(n*sizeof(double));
    v = quickHelper(x, sIndex, eIndex);
    for (i=0; i<n; i++){
        printf("%f   ", v[i]);
    }
    free(v);
    v = NULL;
}


int main() {
    int n, j;
    double* x = NULL;
    printf("Enter the dimension of vector, n:  ");
    scanf("%d", &n);
    x = malloc(n*sizeof(double));
    assert(x!=NULL);
    for (j=0; j<n; j=j+1){
        printf("Enter x[%d] = ", j+1);
        scanf("%lf", &x[j]);
    }

    printf("\nOriginal vector: \n");
    for (j=0; j<n; j=j+1){
        printf("%f  ", x[j]);
    }
    printf("\n\nSorted vector: \n");
    quickSort(x, n);
    free(x);
    x = NULL;
    return 0;
}

// Average case time complexity = O(nlogn)
// Worst case time complexity = O(n^2)
