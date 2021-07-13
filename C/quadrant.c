#include <stdio.h>

void quadrant (float x, float y) {
	if (x == 0 && y != 0) {
		printf("The point (%f, %f) lies on the Y axis", x, y);
	} else if (y == 0 && x != 0) {
		printf("The point (%f, %f) lies on the X axis", x, y);
	} else {
		if (x > 0 && y > 0) {
			printf("The point (%f, %f) lies on the First Quadrant", x, y);
		} else if (x < 0 && y > 0) {
			printf("The point (%f, %f) lies on the Second Quadrant", x, y);
		} else if (x < 0 && y < 0) {
			printf("The point (%f, %f) lies on the Third Quadrant", x, y);
		} else {
			printf("The point (%f, %f) lies on the Fourth Quadrant", x, y);
		}
	}
}

int main () {
	float x, y;
	printf("Enter the value of x: ");
	scanf("%f", &x);
	printf("\nEnter the value of y: ");
	scanf("%f", &y);
	quadrant(x, y);
	return 0;
}
