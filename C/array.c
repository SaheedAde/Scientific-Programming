#include<stdio.h>

const int len = 1000;
const int i = 0;

void printVector (int i) {
	if (i < len) {
		printf("\nx[%d]=%d ", i, i);
		printVector(i+1);
	}
}

void createVector (int x[len], int i) {
	if (i < len) {
		x[i] = i;
		createVector(x, i+1);
	}
}

int main() {
	int x[len];
	createVector(x, i);
	printVector(i);
	return 0;
}
