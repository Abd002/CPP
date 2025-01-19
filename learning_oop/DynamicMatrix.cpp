#include "DynamicMatrix.hpp"

DynamicMatrix::DynamicMatrix(const DynamicMatrix&other){
    this->rows = other.rows;
    this->cols= other.cols;

    this->Matrix = new int*[other.rows];
    for(int i=0;i<other.rows;i++){
        this->Matrix[i] = new int[other.cols];
        
        for(int j=0;j<other.cols;j++){
            this->Matrix[i][j] = other.Matrix[i][j];   
        }
    }

    std::cout<<"Copy Constructor called!"<<std::endl;

}
DynamicMatrix::DynamicMatrix(int row, int col):rows(row), cols(col){
    this->Matrix = new int*[this->rows];
    for(int i=0;i<this->rows;i++){
        this->Matrix[i] = new int[this->cols];
    }
}
DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix&other){
    if(this == &other){
        return *this;
    }
    for(int i=0;i<rows;i++){
        delete[]Matrix[i];
    }
    delete[]Matrix;

    this->rows = other.rows;
    this->cols= other.cols;

    this->Matrix = new int*[other.rows];
    for(int i=0;i<other.rows;i++){
        this->Matrix[i] = new int[other.cols];
        
        for(int j=0;j<other.cols;j++){
            this->Matrix[i][j] = other.Matrix[i][j];   
        }
    }

    std::cout<<"Assignment Operator Called!"<<std::endl;

    return *this;
}
int DynamicMatrix::getValue(int row, int col)const{
    return this->Matrix[row][col];
}

void DynamicMatrix::setValue(int row, int col, int value){
    this->Matrix[row][col] = value;
}
DynamicMatrix::~DynamicMatrix(){
    for(int i=0;i<rows;i++){
        delete[]Matrix[i];
    }
    delete[]Matrix;
}
void DynamicMatrix::print()const{
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            std::cout<<Matrix[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

    
}