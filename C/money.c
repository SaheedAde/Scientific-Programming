#include <stdio.h>

void money (int n) {
	if (n <= 0) {
		printf("\nYou didn't enter a valid amount of money");
	} else {
		if (n/500) {
			printf("\n%d x 500", n/500);
			n = n % 500;
			}
		if (n/100) {
			printf("\n%d x 100", n/100);
			n = n % 100;
		}
		if (n/50) {
			printf("\n%d x 50", n/50);
			n = n % 50;
		}
		if (n/20) {
			printf("\n%d x 20", n/20);
			n = n % 20;
		}
		if (n/10) {
			printf("\n%d x 10", n/10);
			n = n % 10;
		}
		if (n/5) {
			printf("\n%d x 5", n/5);
			n = n % 5;
		}
		if (n/2) {
			printf("\n%d x 2", n/2);
			n = n % 2;
		}
		if (n/1) {
			printf("\n%d x 1", n/1);
			n = n % 1;
		}
	}
}

int main () {
	int n;
	printf("Enter the value of the money: ");
	scanf("%d", &n);
	money(n);
	return 0;
}
