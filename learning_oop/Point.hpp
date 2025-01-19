#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
class Point{
    float x,y;

public:
    Point(float x, float y):x(x),y(y){}
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    float distanceTo(float x, float y)const;
    void print()const;
};

#endif