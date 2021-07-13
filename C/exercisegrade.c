#include <stdio.h>

int main() {
    int solved;
    float percent;
    printf("Enter the number of solved exercises: ");
	scanf("%d", &solved);

	const int SHEETS = 10;
	const int EXERCISES_PER_SHEET = 8;
	const int TOTAL_EXERCISES = SHEETS * EXERCISES_PER_SHEET;
	
	percent = ((float)solved/TOTAL_EXERCISES) * 100;
	
	if (percent >= 50) {
		printf("POSITIVE RESULT");
	} else {
		printf("NEGATIVE RESULT");
	}
    return 0;
}
