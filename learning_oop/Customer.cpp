#include "Customer.hpp"

void Customer::setName(const std::string &name)
{
    this->name = name;
}
void Customer::setAge(int age)
{
    this->age = age;
}

std::string Customer::getName()
{
    return name;
}
int Customer::getAge()
{
    return age;
}

Customer::Customer(const std::string &name, int age, int balance, const std::string &accountNumber) : bankAccount(balance, accountNumber)
{
    this->name = name;
    this->age = age;
}

BankAccount &Customer::getBankAccount()
{
    return bankAccount;
}