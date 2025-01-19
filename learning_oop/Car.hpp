#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>

class Car{
    std::string make;
    std::string model;
    int year;
public:
    Car(const std::string& make,const std::string& model,int year):make(make),model(model),year(year){}

    std::string getMake()const;
    std::string getModel()const;
    int getYear()const;

    void setMake(const std::string& make);
    void setModel(const std::string& model);
    void setYear(int year);

    void print()const;
};

#endif