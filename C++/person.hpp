#ifndef _PERSON_
#define _PERSON_
#include <iostream>

class Person {
    private:
		std::string name;
		std::string address;

    public:
        Person();
        Person(std::string, std::string);
        ~Person();
        std::string getName() const;
        void setName(std::string);
        std::string getAddress() const;
        void setAddress(std::string);
        virtual void print()const;
};

class Student : public Person {
    private:
        int student_number;
        std::string study;

    public:
        Student();
        Student(int, std::string, std::string, std::string);
        ~Student();
        int getStdNum() const;
        void setStdNum(int);
        std::string getStudy() const;
        void setStudy(std::string);
        void print()const;
};

class Employee : public Person {
    private:
        double salary;
        std::string job;

    public:
        Employee();
        Employee(double, std::string, std::string, std::string);
        ~Employee();
        double getSalary() const;
        void setSalary(double);
        std::string getJob() const;
        void setJob(std::string);
        void print() const;

};

#endif // _PERSON_
