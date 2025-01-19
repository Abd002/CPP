#include "Car.hpp"

std::string Car::getMake()const{
    return make;
}
std::string Car::getModel()const{
    return model;
}
int Car::getYear()const{
    return year;
}

void Car::setMake(const std::string& make){
    this->make=make;
}
void Car::setModel(const std::string& model){
    this->model=model;
}
void Car::setYear(int year){
    this->year=year;
}

void Car::print()const{
    std::cout<<"Make : "<<make<<std::endl;
    std::cout<<"model : "<<model<<std::endl;
    std::cout<<"year : "<<year<<std::endl;
}