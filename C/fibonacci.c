#include <stdio.h>

int fibonacci(int k) {
    int xk_1 = 0, xk = 1, sum;
    if (k <= 1) {
        return k;
    }

    for (int i = 0; i < k - 1; i++) {
        sum = xk_1 + xk;
        xk_1 = xk;
        xk = sum;
    }
 
    return xk;
}
 
int main() {
    int k, xk;
	printf("Enter the value of k: ");
	scanf("%d", &k);
	xk = fibonacci(k);
	printf("\nThe value of the %dth fibonacci term is: %d", k, xk);
    return 0;
}


