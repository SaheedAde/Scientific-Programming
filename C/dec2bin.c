#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// declaration of fn pointer that returns array of int
// <return type> (*pointer)(<input>)
int* dec2bin(int N, int* n){
    assert(N>=0 && N<65535);
    int j=0;
    int* v = NULL;

    // memory allocation for array, it accepts bytes as arg,
    // malloc(N*sizeof(type)), where N=16, size of array chosen at will,
    // sizeof(type) converts it byte
    v = malloc(16*sizeof(int));

	// malloc returns NULL if the memory is unassigned.
    assert(v != NULL);
    while (N>0){
		v[j]=N%2;
		N = N/2;
		j++;
	}
    *n = j;

    // what if we return v, j (len of vector) like in python instaed of
    // creating a new pointer *n, just because we want to use the
    // length outside of this function.
    return v;
}

int main (){
    int N, len, j;
    printf("Enter a number, N: ");
    scanf("%d", &N);

    // initialize pointer with NULL (no memory)
    int* v = NULL;

    v = dec2bin(N, &len);
    printf("\n");
    printf("%d in base two = ", N);
    for (j=len-1; j>=0; j--){
          printf("%2d", v[j]);
    }
    printf("\n");
    
    // memory deallocation
    free(v);
    v = NULL;
	return 0;
}

// The code is tested with the example provided in the question i.e for N=77 and other known examples.
