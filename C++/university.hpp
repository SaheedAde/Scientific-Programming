#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

class University {
    private:
        string name;
        string city;
        int num_students;
    public:
        void setName(string);
        void setCity(string);
        void setNumStudent(int);
        void newStudent();
        void graduate();
};

void University::setName(string word){
    name = word;
}
void University::setCity(string cityWord){
    city = cityWord;
}

void University::setNumStudent(int n){
    num_students = n;
}

void University::graduate(){
    assert(num_students > 0);
    int decNum = num_students-1;
    cout << "New number of students:  " << decNum << endl;
}

void University::newStudent(){
    int currNum = num_students + 1;
    cout << "New number of students:  " << currNum << endl;
}





