#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <iostream>

class BankAccount
{
    int balance;
    std::string accountNumber;

public:
    BankAccount(int balance, const std::string accountNumber);

    BankAccount &deposit(int value);
    BankAccount &withdraw(int value);

    std::string getAccountNumber();
    int getBalance();
};

#endif