#include <stdio.h>
#include <math.h>
#define M_PI acos(-1.0)

int main() {
    float r, p, a;
    printf("Enter the radius of the circle: ");
    scanf("%f", &r);
    while(r < 0) {
		printf("Enter radius that is greater than or equal to zero: ");
		scanf("%f", &r);
    }

    p = 2 * M_PI * r;
    a = M_PI * r * r;
    printf("The perimeter of the circle is = %f", p);
    printf("\nThe area of the circle is = %f", a);
    return 0;
}
