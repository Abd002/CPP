#include <iostream>
using namespace std;
class BankException : public exception
{
public:
    virtual const char *what() const noexcept
    {
        return "Bank excpetion occurred\n";
    }
};
class InsufficientFundsException : public BankException
{
public:
    virtual const char *what() const noexcept
    {
        return "InsufficientFundsException occured\n";
    }
};
class NegativeAmountException : public BankException
{
public:
    virtual const char *what() const noexcept
    {
        return "NegativeAmountException occured\n";
    }
};
class BankAccount
{
    double balance;

public:
    BankAccount(double amount) : balance(amount) {}
    void withdraw(double amount)
    {
        if (amount > balance)
            throw InsufficientFundsException();
        if (amount < 0)
            throw NegativeAmountException();
        balance -= amount;
    }
    void print()
    {
        cout << balance << endl;
    }
};
void Try(void);

int main()
{
    BankAccount bankAccount(1000);
    try
    {
        bankAccount.withdraw(10000);
        bankAccount.withdraw(-100);
    }
    catch (BankException &e)
    {
        cout << e.what();
        bankAccount.print();
    }

    Try();
    return 0;
}
