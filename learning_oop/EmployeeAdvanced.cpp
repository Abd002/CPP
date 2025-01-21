#include "EmployeeAdvanced.hpp"

EmployeeAdvanced::EmployeeAdvanced(const std::string &name, int age) : name(name), age(age) {}

void EmployeeAdvanced::displayDetails() const
{
    std::cout << name << ' ' << age << std::endl;
}

int EmployeeAdvanced::getAge() const
{
    return age;
}

void EmployeeAdvanced::setAge(int age)
{
    this->age = age;
}

Manager::Manager(const std::string &name, int age, const std::string &department) : EmployeeAdvanced(name, age), department(department) {}

void Manager::displayDetails() const
{
    std::cout << name << ' ' << age << ' ' << department << std::endl;
}

Engineer::Engineer(const std::string &name, int age, const std::string &specialization) : EmployeeAdvanced(name, age), specialization(specialization) {}

void Engineer::displayDetails() const
{
    std::cout << name << ' ' << age << ' ' << specialization << std::endl;
}