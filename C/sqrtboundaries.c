#include <stdio.h>
#include <assert.h>

int sqrtBoundaries(double x) {
    assert(x>=0);
    double i=1e-7;  // defines the error allowed in calculating the square root of x
    do {
        i+=1e-7;
    }
    while (i*i <=x); // check until i^2 is approximately equals x
    return i;

}

int main() {
    double x;
    printf("Enter the number x: ");
    scanf("%lf", &x);
    printf("%d", sqrtBoundaries(x));
    return 0;
}
