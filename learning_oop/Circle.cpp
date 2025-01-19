#include "Circle.hpp"

float Circle::area()const{
    return PI * this->radius * this->radius;
}

float Circle::circumference()const{
    return 2 * PI * this->radius;
}


