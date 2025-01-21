#include "Person.hpp"
Person::Person(const std::string &name, int age, const std::string &address) : name(name), age(age), address(address) {}
void Person::showDetails() const
{
    std::cout << "From Person class " << name << ' ' << age << ' ' << address << std::endl;
}

Employee_::Employee_(const std::string &name, int age, const std::string &address, const std::string &employeeID) : Person(name, age, address), employeeID(employeeID) {}

void Employee_::showDetails() const
{
    std::cout << "from employee " << employeeID << std::endl;
}

Manager_::Manager_(const std::string &name, int age, const std::string &address, const std::string &employeeID, const std::string &department) : Employee_(name, age, address, employeeID), department(department) {}

void showManagerInfo(const Manager_ &mgr)
{
    std::cout << "showManagerInfo " << mgr.name << ' ' << mgr.age << ' ' << mgr.address << ' ' << mgr.employeeID << std::endl;
}