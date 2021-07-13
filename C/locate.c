#include <stdio.h>

int main() {
    float L, x, y;
    printf("Enter the side length of the square: ");
	scanf("%f", &L);
	while(L <= 0) {
		printf("Enter the side length of the square greater than zero: ");
		scanf("%f", &L);
	}

    printf("Enter the x coordinate: ");
	scanf("%f", &x);

    printf("Enter the y coordinate: ");
	scanf("%f", &y);

	if ((0 < x && x < L) && (0 < y && y < L)) {
		printf("THE POINT IS INSIDE THE SQUARE ");
	} else if (((x == 0 || x == L) && (0 <= y && y <= L)) || ((y == 0 || y == L) && (0 <= x && x <= L))) {
		printf("THE POINT IS ON ITS BOUNDARY ");
	} else {
		printf("THE POINT IS OUTSIDE THE SQUARE ");
	}
    return 0;
}
