#include <stdio.h>
#include <stdlib.h>
#include "datum.h"


//structure to store address
typedef struct Address{
    char* street;
    char* number;
    char* city;
    char* zip;
} Address;

//structure for the new data type Person
typedef struct Person{
    char* firstname;
    char* surname;
    Address* address;
    Date* birthday ;
} Person;

// memory allocation
Address* newAddress(char* street,char* number,char* city,char* zip){

        Address* A = malloc(sizeof(Address));
        assert(A != NULL);
        A->street= street ;
        A->number= number;
        A->city= city;
        A->zip= zip;
        return A;
}
// memory deallocation
Address* delAdress(Address* address ){
    assert(address != NULL);
    free(address->street) ;
    free(address->number);
    free(address->city);
    free(address->zip);
    free(address);
    return NULL;

}

// memory allocation
Person* newperson(char* firstname, char* surname, Address* address, Date* birthday){

    Person* P= malloc(sizeof(Person));
    assert(P != NULL);
    P->firstname = firstname;
    P->surname = surname;
    P->address= address;
    P->birthday= birthday;
    return P;
 }

 // memory deallocation
 Person* delperson(Person* person){
    assert(person != NULL);
    free(person->firstname) ;
    free(person->surname);
    delAdress(person->address);
    delDate(person->birthday);
    free(person);
    return NULL;
}

// writing the function whoIsOlder
Person* whoIsOlder(Person* a, Person* b){

    int da = a->birthday->d;
    int ma = a->birthday->m;
    int ya = a->birthday->y;

    int db = b->birthday->d;
    int mb = b->birthday->m;
    int yb = b->birthday->y;

    if (ya>yb) {
        return b;
    }
    else {
        return a;
    }
    if (ya==yb){

            if (ma>mb){
                    return b;
            }
            else {
                    return a;
            }
     }

    else if ((ya==yb)&&(ma==mb))   {
            if (da>db){
                    return b;
                    }
            else {
                    return a;
                    }
    }
}
