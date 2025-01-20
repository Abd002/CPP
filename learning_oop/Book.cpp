#include "Book.hpp"

Book::Book(const std::string &title, double price)
{
    this->title = title;
    this->price = price;
}
void Book::display() const
{
    std::cout << title << ' ' << price << std::endl;
}

void Book::input(const std::string &title, double price)
{
    this->title = title;
    this->price = price;
}