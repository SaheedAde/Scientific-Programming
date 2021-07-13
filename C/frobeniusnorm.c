#include <stdio.h>
#include <math.h>
#include <time.h>
#include <assert.h>

double frobeniusNorm(double A[], int m, int n){
    assert(m>0 && n>0);
    int mn=m*n;
    double sum_sq=0;

    for (int i=0;i<mn;i++){
        sum_sq = sum_sq+A[i]*A[i];
    }
    return sqrt(sum_sq);
}

int main(){
    int m;
    int n;
    printf("Enter the number of rows of the matrix: ");
    scanf("%d",&m);
    printf("Enter number of columns of the matrix: ");
    scanf("%d",&n);

    double A[n*m];
    clock_t t1;
    clock_t t2;
    int row=1;
    int col=1;

    for (int i=0; i<m*n; i++){
        if(row==m+1) {
            row=1;
            col=col+1;
        }

        printf("\nPlease enter column %d row %d of matrix: ", col, row);
        scanf("%lf", &A[i]);
        row=row+1;
    }
    t1 = clock();
    double frob_norm = frobeniusNorm(A,m,n);
    t2 = clock();
    printf("The Frobenius norm ||A|| = %f\n", frob_norm);

    // Time complexity calculation for the case n
    if (n==m) {
		printf("Time complexity for %d = %d: %f\n", n, m, (double)(t2-t1)/(CLOCKS_PER_SEC));
	}
}

/* The correctness of the code is checked against problems whose answers have been known.
The space complexity is O(n^2).
*/
