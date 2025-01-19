#include "Point.hpp"
#include <math.h>

float Point::getX() const{
    return this->x;
}
float Point::getY() const{
    return this->y;
}
void Point::setX(float x){
    this->x = x;
}
void Point::setY(float y){
    this->y = y;
}
float Point::distanceTo(float x, float y)const{
    return sqrt((this->x-x)*(this->x-x) + (this->y-y)* (this->y-y)); 
}
void Point::print()const{
    std::cout<<this->x <<' '<<this->y<<std::endl; 
}