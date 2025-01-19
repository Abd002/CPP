#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#define PI 3.14

class Circle{
    float radius;

public:
    Circle(float radius):radius(radius){};
    inline float getRadius()const{return radius;}
    inline void setRadius(float radius){this->radius=radius;}
    float area()const;
    float circumference()const;
};

#endif