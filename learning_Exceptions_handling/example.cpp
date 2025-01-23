#include <iostream>
using namespace std;

class CalculatorException : public exception
{
public:
    virtual const char *what() const noexcept
    {
        return "claculator exception \n";
    }
};

class DivisionByZeroException : public CalculatorException
{
public:
    virtual const char *what() const noexcept
    {
        return "Division by zero exception \n";
    }
};
class NegativeSquareRootException : public CalculatorException
{
public:
    virtual const char *what() const noexcept
    {
        return "Negative square root exception\n";
    }
};
class InvalidInputException : public CalculatorException
{
public:
    virtual const char *what() const noexcept
    {
        return "invalid input exception\n";
    }
};

class Calculator
{
public:
    double divide(double a, double b)
    {
        if (b == 0)
            throw DivisionByZeroException();
        return a / b;
    }
    double sqrt(double a)
    {
        if (a < 0)
            throw NegativeSquareRootException();
        return a;
    }
    void readInput()
    {
        string a, b;
        cin >> a >> b;
        bool f = 1;
        for (auto it : a)
        {
            if (it >= '0' && it <= '9')
                continue;
            f = 0;
        }
        for (auto it : b)
        {
            if (it >= '0' && it <= '9')
                continue;
            f = 0;
        }

        if (!f)
            throw InvalidInputException();
    }
};
void Try(void)
{
    Calculator calc;

    try
    {
        calc.divide(5, 3);
        calc.sqrt(5);
        // calc.readInput();
    }
    catch (const CalculatorException &e)
    {
        cout << e.what();
    }
}