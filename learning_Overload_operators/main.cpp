#include <iostream>
using namespace std;

class Complex
{
    double real, imaginary;

public:
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.real << ((c.imaginary >= 0) ? "+" : "") << c.imaginary << 'i';
        return out;
    }

    friend istream &operator>>(istream &in, Complex &c)
    {
        in >> c.real >> c.imaginary;
        return in;
    }
    Complex &operator+(const Complex &c)
    {
        imaginary = imaginary + c.imaginary;
        real = c.real + real;
        return *this;
    }
    Complex &operator-(const Complex &c)
    {
        imaginary = imaginary - c.imaginary;
        real = c.real - real;
        return *this;
    }
    Complex &operator*(const Complex &c)
    {
        imaginary = imaginary * c.imaginary;
        real = c.real * real;
        return *this;
    }
    Complex &operator/(const Complex &c)
    {
        imaginary = imaginary / c.imaginary;
        real = c.real / real;
        return *this;
    }
};

int main()
{
    Complex c1(1, 2);
    Complex c2(1, 4);

    Complex c3 = c1 * c2;
    Complex c4 = c1 / c2;

    c1 = c1 + c2;
    cout << c1 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    cout << c2 << endl;
    return 0;
}