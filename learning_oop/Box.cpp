#include "Box.hpp"

Box::Box(double length, double width, double height) : length(length), width(width), height(height) {}

void BoxManipulator::resize(Box &box, double newLength, double newWidth, double newHeight)
{
    box.height = newHeight;
    box.length = newLength;
    box.width = newWidth;
}
double BoxManipulator::volume(const Box &box)
{
    return (box.height * box.length * box.width);
}