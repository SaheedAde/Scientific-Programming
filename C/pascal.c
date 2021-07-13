#include <stdio.h>
#include <assert.h>

int main() {
    int n;
    int prev_comb = 1;

    printf("Enter the number of rows(n) of Pascal Triangle needed:  ");
    scanf("%d", &n);
    assert(n>0);

    for (int i=0; i<n; i++) {
		for (int empty_space=1; empty_space <= n-i; empty_space++) {
			printf("  ");
		}

		/*
		The following lines use the simple way of calculating elements
		in each row of the Pascal Triangle. We compute each row by
		using nCk = nC_k-1 * (n+1-k/k) for k = 0,1,...,n and using
		the fact that nC_0 = 1 for all n in the set of natural numbers.
		*/

        for (int j=0; j<=i; j++) {
            if (j==0 || i==0) {
                prev_comb = 1;
			}
            else {
                prev_comb=prev_comb*(i+1-j)/j;
			}
			printf("%4d", prev_comb);
        }
        printf("\n");
    }
    return 0;
}
