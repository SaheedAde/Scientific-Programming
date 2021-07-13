#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void cross (int n) {
	assert(n>=2 && n<=9);

	int lines = 2*n-1;

	for(int i=1; i<n+1; i=i+1) {
	  for(int j=1; j<lines+1; j=j+1) {
		if(j==i || j==lines-i+1) {
		  printf(" %d", i);
		}
		else {
		  printf(" ");
		}
	  }
	  printf("\n");
	}

	for(int i=n+1; i<lines+1; i=i+1) {
	  for(int j=1; j<lines+1; j=j+1) {
		if(j==i || j==lines-i+1) {
		  printf(" %d", lines-i+1);
		}
		else {
		  printf(" ");
		}
	  }
	  printf("\n");
	}
}

int main() {
  int n;

  printf("Enter a number from 1 to 9:   ");
  scanf("%d",&n);
  cross(n);
}
