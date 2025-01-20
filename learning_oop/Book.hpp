#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>

class Book
{
    std::string title;
    double price;

public:
    Book(const std::string &title = "", double price = 0.0);
    void display() const;
    void input(const std::string &title, double price);
};

#endif