#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void bubbleSort(double* x, int n){
    assert(n>0);
    int i , j;
    double tmp;

	// loop n times per element
    for(i=0;i<n; i++) {
		// last i elements are sorted already
		for (j=0; j<n-i-1; j++) {
			 // swap if order isn't right
			 if (x[j]>x[j+1]){
				tmp = x[j];
				x[j] = x[j+1];
				x[j+1] = tmp;
			}
		}
    }
    for (j=0; j<n; j++){
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
    bubbleSort(x, n);
    free(x);
    x = NULL;
    return 0;
}

// Number of loops needed for the algorithm = 2
// 1 comparison, 3 assignments
// Computational complexity = sum(from i = 0 to n-1)[sum(from j = 0 to n-2) of {1+3}] = 4(n-1)(n-2)= O(n^2))
// Thus average time complexity = O(n^2) and worst time complexity = O(n^2)
