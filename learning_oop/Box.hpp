#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box
{
    double length, width, height;

public:
    Box(double length, double width, double height);
    friend class BoxManipulator;
};

class BoxManipulator
{

public:
    void resize(Box &box, double newLength, double newWidth, double newHeight);
    double volume(const Box &box);
};

#endif