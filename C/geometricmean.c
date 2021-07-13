#include <math.h>
#include <stdio.h>


float geometricmean(float x[], int n ) {
	float mean, product = 1.0;
	for(int i = 0; i<n; i++) {
		product *= x[i];
	}
	mean = pow(product, (1.0/n));
	
	return mean;
}


int main() {
	int n=5;
	float x[n], inp;

	for (int i = 0; i < n ; ++i) {
		printf("\n Enter Value of Array at Position [%d] : ", i+1);
		scanf("%f", &inp);
		while(inp < 0) {
			printf("Enter a number greater than zero at Position [%d]: ", i+1);
			scanf("%f", &inp);
		}
		x[i] = inp;
	}
	printf("Geometric Mean = %f", geometricmean(x,n));

	return 0;
}
