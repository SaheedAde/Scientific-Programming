#include <iostream>
#include "person.cpp"

using std::cout;
using std::endl;

int main() {

    Person person("Joy Rose", "Gasometer City, Wien");
    Student student(123456, "Technical Mathematics", "Mark Lucas", "Landstrasse, Wien");
    Employee employee(12000.00, "Engineer", "Joseph Andrew", "Erbergstrasse, Wien");

    cout << "---------------------------------------------------------------------------" << endl;

    person.print();

    cout << "---------------------------------------------------------------------------" << endl;

    student.print();

    cout << "---------------------------------------------------------------------------" << endl;

    employee.print();

    cout << "---------------------------------------------------------------------------" << endl;

    return 0;
}

