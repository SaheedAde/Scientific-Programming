#include <stdio.h>

int evenorodd(int n) {
	return ((n % 2 == 0) ? 1 : 0);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    evenorodd(n) ? printf("%d is even.", n) : printf("%d is odd.", n);
    return 0;
}
