#ifndef DYNAMICMATRIX_HPP
#define DYNAMICMATRIX_HPP

#include <iostream>

class DynamicMatrix{
    int rows, cols;
    int **Matrix;

public:
    int getValue(int row, int col)const;

    void setValue(int row, int col, int value);

    DynamicMatrix(const DynamicMatrix& DM);
    DynamicMatrix(int row, int col);

    DynamicMatrix& operator=(const DynamicMatrix&DM);

    ~DynamicMatrix();

    void print()const;

};

#endif