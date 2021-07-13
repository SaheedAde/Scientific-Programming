#include <stdio.h>

float min(float a, float b) {
    return (a < b ? a : b);
}

float max(float a, float b) {
    return (a > b ? a : b);
}

int main() {
    float x, y, z;
    printf("Enter the first number: ");
	scanf("%f", &x);

    printf("Enter the second number: ");
	scanf("%f", &y);

    printf("Enter the third number: ");
	scanf("%f", &z);

	printf("\nTHE MINIMUM NUMBER IS: %f", min(min(x, y), z));
	printf("\nTHE MAXIMUM NUMBER IS: %f", max(max(x, y), z));
    return 0;
}
