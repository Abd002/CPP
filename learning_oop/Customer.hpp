#ifndef COUSTOMER_HPP
#define COUSTOMER_HPP

#include <iostream>
#include "BankAccount.hpp"
class Customer
{
    std::string name;
    int age;
    BankAccount bankAccount;

public:
    Customer(const std::string &name, int age, int balance, const std::string &accountNumber);

    void setName(const std::string &name);
    void setAge(int age);

    std::string getName();
    int getAge();
    BankAccount &getBankAccount();
};

#endif