#include <iostream>
#include <string>
#include "Employee.h"
#include "Circle.hpp"
#include "Point.hpp"
#include "DynamicMatrix.hpp"
#include "Car.hpp"
using namespace std;

struct car_str{
    string make;
    string model;
    int year;

    car_str(const string& make,const string& model,int year){
        this->make=make;
        this->model=model;
        this->year=year;
    }
    void print(){
        std::cout<<"make : "<<make<<std::endl;
        std::cout<<"model : "<<model<<std::endl;
        std::cout<<"year : "<<year<<std::endl;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    Employee one(12,"abd002",32.2);
    Employee two(23, "hossam", 1023.3);
    Employee *three = new Employee(54, "test", 23.4);
    

    one.print();
    two.print();
    three->print();


    Circle* first_circle = new Circle(10);
    Circle second_circle(10);

    cout<<first_circle->area()<<endl;
    cout<<first_circle->circumference()<<endl;
    cout<<second_circle.area()<<endl;
    cout<<second_circle.circumference()<<endl;



    Point * first_point = new Point(5, 5);
    first_point->print();

    cout<<first_point->distanceTo(0 , 0)<<'\n';


    DynamicMatrix* first2D = new DynamicMatrix(3, 4);
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            first2D->setValue(i,j,i*3+j);
        }
    }
    cout<<"first 2D print\n";
    first2D->print();

    DynamicMatrix*second2D = new DynamicMatrix(*first2D);

    cout<<"second 2D print\n";
    second2D->print();

    second2D->setValue(0,0,5);
    second2D->print();

    *second2D = *first2D;

    second2D->print();



    Car *car_class = new Car("hello", "world", 123);
    car_class->print();

    car_str *car_ = new car_str("hello", "world",123);
    car_->print();
    


    return 0;
}


