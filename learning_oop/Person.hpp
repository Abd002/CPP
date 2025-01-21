#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

class Person
{
    std::string name;
    int age;

protected:
    std::string address;

public:
    Person(const std::string &name, int age, const std::string &address);
    virtual void showDetails() const;
    friend void showManagerInfo(const class Manager_ &mgr);
};

class Employee_ : public Person
{
    std::string employeeID;

public:
    Employee_(const std::string &name, int age, const std::string &address, const std::string &employeeID);
    void showDetails() const override;
    friend void showManagerInfo(const class Manager_ &mgr);
};

class Manager_ : public Employee_
{
    std::string department;

public:
    Manager_(const std::string &name, int age, const std::string &address, const std::string &employeeID, const std::string &department);
    friend void showManagerInfo(const class Manager_ &mgr);
};
void showManagerInfo(const Manager_ &mgr);

#endif