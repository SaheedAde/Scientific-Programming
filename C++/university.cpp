#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include "university.hpp"

using namespace std;

int main(){
    string studentName, studentCity;
    int studentNumber;
    University uni;

    cout << "Enter the name of student:  ";
    cin >> studentName;
    cout << "Enter the city of student:  ";
    cin >> studentCity;
    cout << "Enter the number of students:  ";
    cin >> studentNumber;

    uni.setName(studentName);
    uni.setCity(studentCity);
    uni.setNumStudent(studentNumber);

    cout << "------If graduate() is called-----"<< endl;
    uni.graduate();

    cout << "------If newStudent() is called-----"<< endl;
    uni.newStudent();

    return 0;
}
