#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double secant(double (*f)(double), double x0, double x1, double tau) {
  assert(tau>0);
  double x;
  // creates infinite loop using while(1) but terminates with the conditions of the content of the loop
  while(1) {
    x = x1 - f(x1)*((x0-x1)/(f(x0)-f(x1)));
    if ((fabs(f(x)-f(x0)) <= tau)) {
      printf("Warning: result is presumably wrong\n");
      return x;
    } else if (fabs(x) <= tau) {
      if ((fabs(f(x)) <= tau) && (fabs(x - x0) <= tau)) {
        return x;
      }
    } else {
      if ((fabs(f(x)) <= tau) && (fabs(x - x0) <= tau*fabs(x))) {
        return x;
      }
    }
    x0 = x1;
    x1 = x;
  }
}

double f(double x) {
  return x*x - 2;    // x0 = 1, x1 = 2, tau = 0.0001
}


int main() {
  double x0;
  double x1;
  double tau;
  double root;
  printf("x0 = ");
  scanf("%lf",&x0);
  printf("x1 = ");
  scanf("%lf",&x1);
  printf("tau = ");
  scanf("%lf",&tau);

  root = secant(*f, x0, x1, tau);
  printf("Approximate root: x = %.4f \n", root);
  printf("f(x) = %.4f \n", f(root));
  return 0;
}

/* OUTPUTS OF SELECTED EXAMPLES
x0 = 1
x1 = 2
tau = 0.00001
Approximate root: x = 1.4142
f(x) = 0.0000

Process returned 0 (0x0)   execution time : 12.535 s
Press any key to continue.
*/


/* The secant method always converges to a root of f(x)=0 if:
   a) f(x) is continuous on [x0, x1] and f(x0)f(x1)<0;
   b) if the initial guess x0 and x1 are sufficiently close to the root.
*/
