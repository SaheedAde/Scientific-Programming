#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include "name.hpp"
using namespace std;

int main(){
    string firstName;
    string surName;
    Name myname;

    cout << "Enter your first name, if more than one, delimiter by '_'  " << endl;   // e.g Rasheed_Oyewole
    cin >> firstName;
    cout << "Enter your Surname" << endl;
    cin >> surName;
    myname.setFirstName(firstName);
    myname.setSurname(surName);

    myname.setFullName(firstName);
    myname.printName();

    return 0;
}
