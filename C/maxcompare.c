#include <stdio.h>
#include <assert.h>

/* We write a function maxVector which computes the maximum of each vector,
and then is called in the function maxCompare
*/

double maxVector(double v[], int dim){
    assert(dim>0);
    int j;
    double max = v[0];
    for (j=0; j<dim; j=j+1){
		if (v[j]>max){
			max = v[j];
		}
    }
    return max;
}

int maxCompare(double a[], double b[], int dim){
    int j;
    int count = 0;
    double max1 = maxVector(a, dim);
    double max2 = maxVector(b, dim);

    for (j=0; j<dim; j=j+1){
        if (a[j]==max1 && b[j]==max2 && max1==max2){
            count = count+1;
        }
    }
    return count;
}

int main() {
    int dim;
    int j;
    printf("Enter the number of elements in the vector:  ");
    scanf("%d", &dim);
    double a[dim];
    double b[dim];

    // The user is prompted to enter the elements of each vector

    for (j=0; j<dim; j++){
        printf("\nEnter element %d of the fist vector:  ", j+1);
        scanf("%lf", &a[j]);
    }
    for (j=0; j<dim; j++){
        printf("\nEnter element %d of the second vector:  ", j+1);
        scanf("%lf", &b[j]);
    }
    printf("Number of occurrence of the global maximum of the vectors = %d", maxCompare(a,b,dim));
	return 0;
}
// The correctness of the code is checked against problems whose answers have been known.

