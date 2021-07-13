#include <stdio.h>
#include <math.h>
#include <assert.h>

double cubeRoot(double x, double precision) {

    assert(precision>0); // ensure precision is nonnegative

    /*
    We use the fact that a number i is  the cube root
    of a number x if i*i*i = x. To find i, we initialize
    i with a very small real number called 'precision'
    (e.g precision = 1e-7) then increasing i gradually
    with 'precision' until i*i*i = x
    */

    double i;
    if (x==0) return 0;

    //this part handles negative x
    else if (x < 0) {
		i = precision;
		do {
			i += precision;
		}
		while(i*i*i <= -x);
		return -i;
    }
    // this part handles positive x
	i = precision;
	do {
		i += precision;
	}
	while(i*i*i <= x);
	return i;
}

/*
We test the validity of the function cubeRoot by calling the cbrt
function in math library and compare the result with our function.
*/

int main() {
    double x;
    double precision;
    printf("Enter a number, x:  ");
    scanf("%lf", &x);
    printf("Enter precision:  ");
    scanf("%lf", &precision);
    printf("Estimated cube root:  %f \n", cubeRoot(x, precision));
    printf("Math library result:   %f", cbrt(x));
    return 0;
}
