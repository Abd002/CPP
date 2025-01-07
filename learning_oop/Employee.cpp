#include "Employee.h"

int Employee::employeeCount = 0;

Employee::Employee(int id, string name, double salary):id(id), name(name),salary(salary){
    employeeCount++;
}

int Employee::getId(){
    return this->id;
}
string Employee::getName(){
    return this->name;
}
double Employee::getSalary(){
    return this->salary;
}
int Employee::getEmployeeCount(){
    return this->employeeCount;
}
void Employee::print(){
    cout<<"id: "<<this->id<<endl;
    cout<<"name: "<<this->name<<endl;
    cout<<"salary: "<<this->salary<<endl;
    cout<<"employeeCount: "<<this->employeeCount<<endl;
}

void Employee::setId(int id){
    this->id=id;
}

void Employee::setName(string name){
    this->name=name;
}
void Employee::setSalary(double salary){
    this->salary=salary;
}
Employee::~Employee(){
    this->employeeCount--;
}
