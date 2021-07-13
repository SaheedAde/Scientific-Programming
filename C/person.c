#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "person.h"
#define charLen 255  // define maximum number of characters, could be changed!!

typedef struct Date  Date;
typedef struct Address Address;
typedef struct Person Person;

main(){
    // first person information
    char* firstname1= malloc(charLen*sizeof(char));
    char* surname1=malloc(charLen*sizeof(char));

    printf("Please enter your firstname:   \n");
    scanf("%s", firstname1);
    printf("Please enter your surname:   \n");
    scanf("%s", surname1);

    char* street1=malloc(charLen*sizeof(char));
    char* number1=malloc(charLen*sizeof(char));
    char* city1=malloc(charLen*sizeof(char));
    char* zip1=malloc(charLen*sizeof(char));

    printf("Please enter your street name:  \n");
    scanf("%s", street1);
    printf("Please enter your street number:   \n");
    scanf("%s", number1);
    printf("Please enter your city:   \n");
    scanf("%s", city1);
    printf("Please enter your zip:   \n");
    scanf("%s", zip1);

    int  d1,m1, y1;

    printf("Please enter your birth day:   ");
    scanf("%d",&d1);
    printf("Please enter your birth month:   ");
    scanf("%d",&m1);
    printf("Please enter your birth year:   ");
    scanf("%d",&y1);

    Date* birthday1= newDate(d1,m1,y1);
    Address* address1= newAddress(street1,number1,city1,zip1);
    Person* person1 =  newperson (firstname1,  surname1,  address1,  birthday1);

    // personal information for the second person
    char* firstname2=malloc(charLen*sizeof(char));
    char* surname2=malloc(charLen*sizeof(char));

    printf("Please enter your firstname:   \n");
    scanf("%s", firstname2);
    printf("Please enter your surname:   \n");
    scanf("%s", surname2);

    char* street2=malloc(charLen*sizeof(char));
    char* number2=malloc(charLen*sizeof(char));
    char* city2=malloc(charLen*sizeof(char));
    char* zip2=malloc(charLen*sizeof(char));

    int d2, m2, y2;
    printf("Please enter your birth day:   ");
    scanf("%d",&d2);
    printf("Please enter your birth month:   ");
    scanf("%d",&m2);
    printf("Please enter your birth year:   ");
    scanf("%d",&y2);

    Date* birthday2= newDate(d2, m2, y2);
    Address* address2 = newAddress(street2, number2, city2, zip2);
    Person* person2 =  newperson (firstname2,  surname2,  address2,  birthday2);

    Person* checkPerson =  whoIsOlder(person1, person2);
    char* checkOlder = checkPerson->firstname;

    // return the firstname of the older
    printf("The oldest person is %s \n ", checkOlder);
}
