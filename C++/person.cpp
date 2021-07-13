#include <iostream>
#include "person.hpp"

using std::cout;
using std::endl;

Person::Person() {
      cout << "Person: BaseClass()\n";
}
Person::Person(std::string  name, std::string address){
    this -> name = name;
    this -> address = address;
}
Person::~Person() {
    cout << "~Person: BaseClass()\n";
}
std::string Person::getName() const { return name; }
void Person::setName(std::string nm) { name = nm; }
std::string Person::getAddress() const {return address; }
void Person::setAddress(std::string addr) { address = addr; }
void Person::print()const {
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
}

Student::Student() {
   cout << "Student: DerivedClass()\n";
}
Student::Student(int studentNum, std::string studentStudy, std::string studentName, std::string studentAddress){
    student_number = studentNum;
    study = studentStudy;
    setName(studentName);
    setAddress(studentAddress);
}
Student::~Student() {
    cout << "~Student: DerivedClass()\n";
}
int Student::getStdNum() const { return student_number; }
void Student::setStdNum(int num) { student_number = num; }
std::string Student::getStudy() const { return study; }
void Student::setStudy(std::string st) { study = st; }
void Student::print() const{
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Student Number: " << getStdNum() << endl;
    cout << "Study: " << getStudy() << endl;
}

Employee::Employee() {
    cout << "Employee: DerivedClass()\n";
}
Employee::Employee(double employeeSal, std::string employeeJob, std::string employeeName, std::string employeeAddress){
    salary = employeeSal;
    job = employeeJob;
    setName(employeeName);
    setAddress(employeeAddress);
}
Employee::~Employee() {
    cout << "~Employee: DerivedClass()\n";
}
double Employee::getSalary() const { return salary; }
void Employee::setSalary(double sal) { salary = sal; }
std::string Employee::getJob() const { return job; }
void Employee::setJob(std::string jb) { job = jb; }
void Employee::print() const{
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Salary: " << getSalary() << endl;
    cout << "Job: " << getJob() << endl;
}
