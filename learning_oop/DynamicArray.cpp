#include "DynamicArray.hpp"

DynamicArray::DynamicArray(int size)
{
    data = new int[size];
    this->size = size;
}

void DynamicArray::setValue(int index, int value)
{
    data[index] = value;
}

int DynamicArray::getValue(int index) const
{
    return data[index];
}

DynamicArray::~DynamicArray()
{
    delete[] data;
    std::cout << "deleted\n";
}