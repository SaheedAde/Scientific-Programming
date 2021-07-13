#include <stdio.h>

void scanfPositive(){
	double tau;
    do {
		printf("Enter a number: ");
		scanf("%lf", &tau);
    }
    while (tau <= 0);
    printf("Positive number supplied:  %f", tau);
}

int main(){
    scanfPositive();
    return 0;
}
