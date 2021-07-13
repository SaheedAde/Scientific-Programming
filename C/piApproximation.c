#include <stdio.h>
#include <math.h>

double partialSum (int n) {
	double Sn = 0;
	if (n < 0) {
		printf("\nYou didn't enter a valid number for n");
	} else {
		for (int k = 0; k <= n; ++k) {
			Sn += (4 * pow(-1, k))/((2 * k) + 1);
		}
	}
	return Sn;
}

double partialSumRecursive (double Sn, int n, int k) {
	if (n < 0) {
		printf("\nYou didn't enter a valid number for n");
	} else {
		if (k <= n) {
			Sn += (4 * pow(-1, k))/((2 * k) + 1); //holds current value
			Sn = partialSumRecursive(Sn, n, k+1); //holds next value
		}
	}
	return Sn;
}

int main () {
	int n;
	double Sn;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	Sn = partialSum(n);
	printf("\nThe value of pi with loop is: %lf", Sn);
	Sn = partialSumRecursive(0, n, 0);
	printf("\nThe value of pi with recursion is: %lf", Sn);
	return 0;
}
