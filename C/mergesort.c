#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void mergeSort(double* x, int n){
	assert(n>0);
	double* L;
	double* R;
	double arr_cach[n];
	int i=0;
	int j=0;
	int k=0;
	double currElmt;


	// base case
	if (n==2){
		if(x[0]>x[1]){
			currElmt= x[1];
			x[1]=x[0];
			x[0]=currElmt;
		}
	}

	// case n>2
	if (n>2){
		// divide x into left and right array
		// L = left array
		// R = Right array
		mergeSort(x,(n/2));
		L=x;
		mergeSort((x+(n/2)),(n+1)/2);
		R=(x+(n/2));

		while ((i<n/2)&&(j<(n+1)/2)) {
			while ((L[i]>=R[j])) {
				arr_cach[k]=R[j];
				k++;
				j++;
				if (j>=(n+1)/2) break;
			}

			while(L[i]<=R[j]){
				arr_cach[k]=L[i];
				k++;
				i++;
				if (i>=(n/2)) break;
			}

		}

		if (i>=(n/2)){
			while (j<=(n+1)/2){
				arr_cach[k]=R[j];
				k++;
				j++;
			}
		}

		if (j>=((n+1)/2)){
			while (i<=n/2){
				arr_cach[k]=L[i];
				k++;
				i++;
			}
		}
		for(i=0;i<n;i++){
			x[i]=arr_cach[i];
		}
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
    mergeSort(x, n);
    for (j=0; j<n; j=j+1){
        printf("%f  ", x[j]);
    }
    free(x);
    x = NULL;
    return 0;
}


//Average and worst case time complexity = nlog(n) due to the recursion

