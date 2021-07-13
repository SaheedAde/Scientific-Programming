#include<stdio.h>

int binomial(int n, int k) {
	if ((k == 0) || (k == n)) return 1;
	if (k > n) return 0;
	return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main() {
	int k, n, res;
	printf("\nEnter the value of n: ");
	scanf("%d", &n);
	printf("Enter the value of k: ");
	scanf("%d", &k);
	res = binomial(n, k);
	printf("The result is %d", res);
	return 0;
}
