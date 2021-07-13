#include <stdio.h>
#include <stdlib.h>
#define MAX_YR  2021  // could be changed !!
#define MIN_YR  1900

//structure to store date
typedef struct Date{
    int y;
    int m;
    int d;
} Date;

// memory allocation and initialization


Date* newDate(int d, int m, int y){
    Date* X = malloc(sizeof(Date));
    assert(X != NULL);
    X -> d = d;
    X -> m = m;
    X -> y = y;
    return X;
}


// memory deallocation
Date* delDate(Date* date){
    assert(date != NULL);
    free(date);
    return NULL;
}

// set mutator functions
void setDateDay(Date* date, int d){
    date -> d = d;
}

void setDateMonth(Date* date, int m){
    date -> m = m;
}

void setDateYear(Date* date, int y){
    date -> y = y;
}

// get mutator functions
int getDateDay(Date* date){
    return date -> d;
}

int getDateMonth(Date* date){
    return date -> m;
}

int getDateYear(Date* date){
    return date -> y;
}


// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

int isMeaningful(Date *date)

{
    //check range of year,month and day
    if (date->y > MAX_YR ||
            date->y < MIN_YR)
        return 0;
    if (date->m < 1 || date->m > 12)
        return 0;
    if (date->d < 1 || date->d > 31)
        return 0;
    //Handle feb days in leap year
    if (date->m == 2)
    {
        if (IsLeapYear(date->y))
            return (date->d <= 29);
        else
            return (date->d <= 28);
    }
    //handle months which has only 30 days
    if (date->m == 4 || date->m == 6 ||
            date->m == 9 || date->m == 11)
        return (date->d <= 30);
    return 1;
}
