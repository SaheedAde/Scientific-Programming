#include <stdio.h>

float square(float num) {
    return (num*num);
}

int main() {
    int a, b, c;
    printf("Enter the first side of the triangle: ");
	scanf("%d", &a);

    printf("Enter the second side of the triangle: ");
	scanf("%d", &b);

    printf("Enter the third side of the triangle: ");
	scanf("%d", &c);
	
	if (a+b==c || a+c==b || b+c==a) {
		//1-dim degenerate case
		printf("DEGENERATE TRIANGLE");
	} else if (a+b<c || a+c<b || b+c<a) {
		//impossible case
		printf("IMPOSSIBLE TRIANGLE");
	} else {
		if (a == b && b == c) {
			//equilatteral case
			printf("EQUILATERAL TRIANGLE");
		}
		if (a == b || a == c || b == c) {
			//iscocelles case
			printf("ISOCELLES TRIANGLE");
		} else {
			if ((square(a) + square(b)) == square(c) || (square(b) + square(c)) == square(a) || (square(a) + square(c)) == square(b)) {
				//right angle case
				printf("RIGHT ANGLE TRIANGLE");
			} else {
				printf("ANOTHER TYPE OF TRIANGLE");
			}
		}
	}
    return 0;
}
