#include <iostream>
#include "Employee.h"
#include "Circle.hpp"
#include "Point.hpp"
using namespace std;

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


    return 0;
}


