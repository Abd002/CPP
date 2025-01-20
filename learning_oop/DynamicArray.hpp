#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>

class DynamicArray
{
    int *data;
    int size;

public:
    DynamicArray(int size);

    void setValue(int index, int value);

    int getValue(int index) const;

    ~DynamicArray();
};

#endif