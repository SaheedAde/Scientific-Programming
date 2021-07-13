#include <stdio.h>

void divisor (int x) {
	if ((x % 2 == 0) || (x % 3 == 0) || (x % 6 == 0)) {
		printf("%d IS DIVISIBLE BY 2, 3 OR 6", x);
	} else {
		printf("%d IS NOT DIVISIBLE BY 2, 3 OR 6", x);
	}
}

int main() {
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    divisor(x);
    return 0;
}
