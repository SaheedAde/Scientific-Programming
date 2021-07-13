#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double newton (double (*f)(double), double (*fprime)(double), double x0, double tau) {
  assert(tau>0);
  double x;
  // creates infinite loop using while(1) but terminates with the conditions of the content of the loop
  while(1) {
    x = x0 - (f(x0)/fprime(x0));
    if ((fabs(fprime(x)) <= tau)) {
      printf("Warning: result is presumably wrong\n");
      return x;
    }
    else if (fabs(x) <= tau) {
      if ((fabs(f(x)) <= tau) && (fabs(x - x0) <= tau)) {
        return x;
      }
    }
    else {
      if ((fabs(f(x)) <= tau) && (fabs(x - x0) <= tau*fabs(x))) {
        return x;
      }
    }
    x0 = x;
 }
}

double f(double x) {
  return x*x - 2;    // x0 = 1, x1 = 2, tau = 0.0001
}

double fprime(double x) {
    return 2*x;
}


int main() {
  double x0;
  double tau;
  double root;
  printf("x0 = ");
  scanf("%lf",&x0);
  printf("tau = ");
  scanf("%lf",&tau);

  root = newton(*f, *fprime, x0, tau);
  printf("Approximate root: x = %.4f \n", root);
  printf("f(x) = %.4f \n", f(root));
  return 0;
}

/* OUTPUT OF SELECTED EXAMPLE
x0 = 1
tau = 0.00001
Approximate root: x = 1.4142
f(x) = 0.0000

Process returned 0 (0x0)   execution time : 26.994 s
Press any key to continue.
*/


/* The newton method always converges to a root of f(x)=0 if:
   a) f(x) and its first derivative is continuous on [a, b] containing the root;
   b) if the initial guess x0 sufficiently close to the root;
   c) if f(x) is differentiable at x0 and f'(x0) is not equal to zero.
*/
