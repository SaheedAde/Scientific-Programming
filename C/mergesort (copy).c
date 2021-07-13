#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(double* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; //len of left side
    int n2 = r - m;  // len of the right side
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(double* arr, int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
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
    mergeSort(x, 0, n-1);
    for (j=0; j<n; j=j+1){
        printf("%f  ", x[j]);
    }
    free(x);
    x = NULL;
    return 0;
}


//Average and worst case time complexity = nlog(n) due to the recursion

