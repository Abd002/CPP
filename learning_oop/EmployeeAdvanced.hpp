#ifndef EMPLOYEE_ADVANCED_HPP
#define EMPLOYEE_ADVANCED_HPP

#include <iostream>

class EmployeeAdvanced
{
protected:
    std::string name;
    int age;

public:
    EmployeeAdvanced(const std::string &name, int age);

    virtual void displayDetails() const;

    int getAge() const;

    void setAge(int age);
};

class Manager : public EmployeeAdvanced
{
    std::string department;

public:
    Manager(const std::string &name, int age, const std::string &department);
    void displayDetails() const override;
};

class Engineer : public EmployeeAdvanced
{
    std::string specialization;

public:
    Engineer(const std::string &name, int age, const std::string &specialization);
    void displayDetails() const override;
};
#endif