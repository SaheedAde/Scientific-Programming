#include <stdio.h>
#include <assert.h>

void pythagoras(int n){
	// ensures n is a natural number and n>=5 since no Pythagorean triple between 1 and 5
    assert(n>=5);

    int j, k, l;
    int v[n];
    for (j=0; j<=n; j++){
        v[j]=j+1;
    }

    for (j=0; j<n; j++) {
		for (k=j+1; k<n; k++){
			for (l=k+1; l<n; l++){
				if (v[j]*v[j] + v[k]*v[k] == v[l]*v[l]) {
					printf("(%d, %d, %d)\n", v[j], v[k], v[l]);
				}
			}
		}
    }

}

int main () {
    int n;
    printf("Enter the value of n:  ");
    scanf("%d", &n);
    pythagoras(n);
    return 0;
}

