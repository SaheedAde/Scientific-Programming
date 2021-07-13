#include <stdio.h>

double minabs(double x, double y) {
	double xt = x;
	double yt = y;
	if (xt < 0) {
		xt *= -1;
	}
	if (yt < 0) {
		yt *= -1;
	}
	return xt > yt ? y : x;
}

int main() {
    double x, y;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the value of y: ");
    scanf("%lf", &y);

    printf("Number with minimum absolute value = %f", minabs(x,y));
    return 0;
}
