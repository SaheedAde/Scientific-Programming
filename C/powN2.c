#include <stdio.h>

double powN (int n, double x) {
	double exp = 1;
	if (n < 0) {
		n *= -1;
		if (x) {
			for (int k = 1; k <= n; ++k) {
				exp *= (double)1/x;
			}
		} else {
			return 0.0/0.0;
		}
	} else if (n > 0) {
		if (x) {
			for (int k = 1; k <= n; ++k) {
				exp *= x;
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
	exp = powN(n, x);
	printf("\nThe value of %lf^%d is: %lf", x, n, exp);
	return 0;
}
