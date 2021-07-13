#include<stdio.h>

float scalarproduct (double u[3], double v[3]) {
	float w;
	w = (u[0]*v[0]) + (u[1]*v[1]) + (u[2]*v[2]);
	return w;
}

int main() {
	float a, b, c, x, y, z, w;
	printf("\nEnter the value of a: ");
	scanf("%f", &a);
	printf("\nEnter the value of b: ");
	scanf("%f", &b);
	printf("\nEnter the value of c: ");
	scanf("%f", &c);
	printf("\nEnter the value of x: ");
	scanf("%f", &x);
	printf("\nEnter the value of y: ");
	scanf("%f", &y);
	printf("\nEnter the value of z: ");
	scanf("%f", &z);
	double u[3] = {a, b, c};
	double v[3] = {x, y, z};
	w = scalarproduct(u, v);
	printf("The result of the scalar product is w = %f", w);
	return 0;
}
