#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<assert.h>
#include "datum.h"
#define MAX_YR  2021  // could be changed depending on the range of year needed!!
#define MIN_YR  1900

//typedef struct Date Date;


int main() {
     Date** date=malloc(1*sizeof(Date*));
     int counter=0 ;
     int  y , m , d ;
     int i;

     for (y=MIN_YR; y <= MAX_YR; y++){
		for( m=1;m <=12; m++){
		  for(d=1; d<=31; d++){
			Date* testDate = newDate(d,m,y);
			if (isMeaningful(testDate)){
				date[counter]= testDate;
				counter++;
				date=realloc(date, (counter+1)*sizeof(Date*));
			}
			else {
				delDate(testDate);
			}
		  }
		}
	}
    // displays the contents of the struct Date, can be comment if you don't want to see the contents of the struct
    for (i=0; i<counter; i++){
		printf("Date: %d . %d . %d \n", date[i]->d, date[i]->m, date[i]->y );
    }

    int  inDay, inMonth, inYear, checkDate;

    printf("Please enter day:   ");
    scanf("%d", &inDay);
    printf("Please enter month:  ");
    scanf("%d", &inMonth);
    printf("Please enter year:   ");
    scanf("%d", &inYear);
    assert(inDay>0 && inMonth>0 && inYear>0);

    // return 1 if input date is valid and return 0 if invalid
    checkDate = isMeaningful(newDate(inDay, inMonth, inYear));
    printf("\n %d", checkDate);

	return 0;
}
