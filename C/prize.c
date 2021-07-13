#include <stdio.h>

int main() {
    float x, y;
    int n;
    printf("Enter the win amount of the game: ");
    scanf("%f", &x);
    while(x <= 0) {
		printf("Enter the win amount of the game greater than zero: ");
		scanf("%f", &x);
    }

    printf("Enter the number of friends: ");
    scanf("%d", &n);
    while(n <= 0) {
		printf("Enter the number of friends greater than zero: ");
		scanf("%d", &n);
    }
    y = x / (float)n;
    printf("Each of your friends will have = %f", y);
    return 0;
}
