#include <stdio.h>

int SIZE = 4;

void cut (int y[SIZE], int n) {
	int toRemove = 0;
	/* iterate the array elements,
	 * if any element matches the key, store the index */
    for (int i = 0; i < SIZE; i++) {
        if(y[i] >= n) {
			toRemove += 1;
			for (int k = i; k < SIZE - 1; k++) {
				y[k] = y[k+1];
			}
			//cut(y, n);
			/* Decrement array size by 1 */
			//SIZE--;
        }
    }

	printf("New Array : ");
	for(int i = 0; i < SIZE - toRemove; i++) {
		printf("%d ",y[i]);
	}
}

int main () {
	int x[SIZE], n;

	printf("Enter the value of bound n: ");
	scanf("%d", &n);

	for (int i = 0; i < SIZE ; i++) {
		printf("\n Enter Value of Array at Position [%d] : ", i+1);
		scanf("%d", &x[i]);
	}
	cut(x, n);
	return 0;
}
