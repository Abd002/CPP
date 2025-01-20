#include "BankAccount.hpp"

BankAccount &BankAccount::deposit(int value)
{
    balance += value;
    return *this;
}
BankAccount &BankAccount::withdraw(int value)
{
    balance -= value;

    return *this;
}

std::string BankAccount::getAccountNumber()
{
    return accountNumber;
}
int BankAccount::getBalance()
{
    return balance;
}
BankAccount::BankAccount(int balance, const std::string accountNumber) : balance(balance), accountNumber(accountNumber) {}
