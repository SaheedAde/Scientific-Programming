#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <locale>
using namespace std;

class Name{
    private:
        string first_name;
        string surname;

        // additional variables
        string lName;
        string fName;
        int counter;

    public:
        void setFirstName(string);
        void setSurname(string);
        void setFullName(string);
        void printName();
};

void Name::setFirstName(string myFirstName){
    first_name = myFirstName;
}

void Name::setSurname(string mySurname){
    surname = mySurname;
}

void Name::setFullName(string name){
  counter = 0;
  int i;
  for (i = 0; i < name.length(); i++){
    if (isupper(name[i])){
        counter++;
    }
  }
  if (counter>=2){
    size_t pos = name.find("_");    // if first name are multiple, it is delimiter by '_'
    fName = name.substr(0, pos);
    lName = name.substr(pos, std::string::npos);
  }
  else {
    fName = name;
  }
}

void Name::printName(){
    if (counter >=2){
        cout << fName + " " + " " + lName[1] + ". " + surname << endl;
    }
    else{
        cout << first_name + " " + surname << endl;
    }
}


