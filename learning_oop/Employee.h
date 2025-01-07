#ifndef EMPLOYEE_H__
#define EMPLOYEE_H__

#include <iostream>
using namespace std;

class Employee{
    int id;
    string name;
    double salary;

    static int employeeCount;

public:
    
    Employee(int,string,double);

    int getId();
    string getName();
    double getSalary();
    int getEmployeeCount();

    void print();

    void setId(int);
    void setName(string);
    void setSalary(double);

    ~Employee();
};
#endif
