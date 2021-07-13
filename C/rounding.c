#include <stdio.h>

int rounding (float x) {
	int whole;
	float rem;
	whole = (int)x;
	rem = x - (float)whole;
	if (rem < 0.5) {
		return whole;
	}
	return whole + 1;
}

int main() {
    float x;
    printf("Enter the value of x: ");
    scanf("%f", &x);
    printf("\nThe round of %f is %d", x, rounding(x));
    return 0;
}
