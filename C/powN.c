#include <stdio.h>

double powN (int n, double x, double exp, int k) {
	if (n < 0) {
		n *= -1;
		if (x) {
			if (k <= n) {
				exp *= (double)1/x;
				n *= -1;
				exp = powN(n, x, exp, k+1);
			}
		} else {
			return 0.0/0.0;
		}
	} else if (n > 0) {
		if (x) {
			if (k <= n) {
				exp *= x;
				exp = powN(n, x, exp, k+1);
			}
		} else {
			return 0;
		}
	} else {
		if (x) {
			return 1;
		}
		return 0.0/0.0;
	}
	return exp;
}

int main () {
	int n;
	double x, exp;
	printf("Enter the value of x: ");
	scanf("%lf", &x);
	printf("Enter the value of n: ");
	scanf("%d", &n);
	exp = powN(n, x, 1, 1);
	printf("\nThe value of %lf^%d is: %lf", x, n, exp);
	return 0;
}
