#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int checkOccurrence(char* string, char character){
    assert(string!=NULL);
    int length, j;
    int counter = 0;
    length = strlen(string);
    for (j=0; j<length; j=j+1){
        if (tolower(string[j])==tolower(character)){     // convert to lower before comparison
            counter += 1;
        }
    }
    return counter;
}

int main() {
    char* string = NULL;
    char character;
    string = malloc(255*sizeof(char)); // maximum length of 255 characters, can be modified
    printf("Enter a string:  ");
    gets(string);
    printf("Enter a character to be searched:  ");
    scanf("%c", &character);
    printf("\nNumber of occurrence:  %d \n", checkOccurrence(string, character));
    free(string);
    string = NULL;
    return 0;
}

/* OUTPUT OF TEST EXAMPLE
Enter a string:  RasHeEd
Enter a character to be searched:  e

Number of occurrence:  2

Process returned 0 (0x0)   execution time : 21.323 s
Press any key to continue.
*/
