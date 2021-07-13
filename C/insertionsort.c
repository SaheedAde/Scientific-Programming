#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(double* x, int n){
    assert(n>0);
    int i, k;
    double current_elmnt;
    for(i = 1; i < n ; i++){
        current_elmnt = x[i];
        k = i - 1;

        while(k >= 0 && (x[k] > current_elmnt)){
            x[k+1] = x[k];
            k = k - 1;
        }
        x[k+1] = current_elmnt;
    }
    for (k=0; k<n; k++){
        printf("%f  ", x[k]);
    }
}

int main () {
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
    insertionSort(x, n);
    free(x);
    x = NULL;
    return 0;
}

// Average time complexity = O(n^2)
// Worst time complexity = O(n^2)




