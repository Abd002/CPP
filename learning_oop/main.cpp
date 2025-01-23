#include <iostream>
#include <string>
#include "Employee.h"
#include "Circle.hpp"
#include "Point.hpp"
#include "DynamicMatrix.hpp"
#include "Car.hpp"
#include "DynamicArray.hpp"
#include "Book.hpp"
#include "Customer.hpp"
#include "Worker.hpp"
#include "EmployeeAdvanced.hpp"
#include "Box.hpp"
#include "Person.hpp"
using namespace std;

void Try(void);

struct car_str
{
    string make;
    string model;
    int year;

    car_str(const string &make, const string &model, int year)
    {
        this->make = make;
        this->model = model;
        this->year = year;
    }
    void print()
    {
        std::cout << "make : " << make << std::endl;
        std::cout << "model : " << model << std::endl;
        std::cout << "year : " << year << std::endl;
    }
};

void modifyWithPointer(int *x)
{
    (*x) += 10;
}
void modifyWithReference(int &x)
{
    x += 20;
}

int main()
{
    cout << "Hello, World!" << endl;
    Employee one(12, "abd002", 32.2);
    Employee two(23, "hossam", 1023.3);
    Employee *three = new Employee(54, "test", 23.4);

    one.print();
    two.print();
    three->print();

    Circle *first_circle = new Circle(10);
    Circle second_circle(10);

    cout << first_circle->area() << endl;
    cout << first_circle->circumference() << endl;
    cout << second_circle.area() << endl;
    cout << second_circle.circumference() << endl;

    Point *first_point = new Point(5, 5);
    first_point->print();

    cout << first_point->distanceTo(0, 0) << '\n';

    DynamicMatrix *first2D = new DynamicMatrix(3, 4);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            first2D->setValue(i, j, i * 3 + j);
        }
    }
    cout << "first 2D print\n";
    first2D->print();

    DynamicMatrix *second2D = new DynamicMatrix(*first2D);

    cout << "second 2D print\n";
    second2D->print();

    second2D->setValue(0, 0, 5);
    second2D->print();

    *second2D = *first2D;

    second2D->print();

    Car *car_class = new Car("hello", "world", 123);
    car_class->print();

    car_str *car_ = new car_str("hello", "world", 123);
    car_->print();

    {
        DynamicArray dynamic_array(10);
        for (int i = 0; i < 10; i++)
        {
            dynamic_array.setValue(i, i + 1);
            cout << dynamic_array.getValue(i) << ' ';
        }
        cout << endl;
    }
    DynamicArray *arr = new DynamicArray(10);
    delete arr;

    int x = 50;
    modifyWithPointer(&x);
    cout << x << endl;
    modifyWithReference(x);
    cout << x << endl;

    Book *book_arr = new Book[3];
    for (int i = 0; i < 3; i++)
    {
        book_arr[i].input("abc", i * 3.12);
        book_arr[i].display();
    }
    delete[] book_arr;

    Customer firstCustomer("abd002", 21, 10000, "12334568989");

    firstCustomer.getBankAccount().withdraw(100).deposit(100);
    cout << firstCustomer.getBankAccount().getBalance() << endl;
    {
        FullTimeWorker f_worker("abd002", 22000);
        PartTimeWorker p_worker("abd002", 100);
        Worker *bptr[] = {&f_worker, &p_worker};
        p_worker.setHoursWorked(100);
        for (auto it : bptr)
        {
            it->displaySalary();
        }
    }

    Manager manager("salah", 23, "programming");
    Engineer engineer("Abd002", 22, "ps");
    EmployeeAdvanced *employees[] = {&manager, &engineer};

    for (auto it : employees)
    {
        it->displayDetails();
    }

    Box box(1, 2, 3);
    BoxManipulator ok;
    cout << ok.volume(box) << endl;
    ok.resize(box, 5, 5, 5);
    cout << ok.volume(box) << endl;

    Manager_ manager_("Abd002", 22, "Cairo", "12345", "Engineering");
    manager_.showDetails();
    showManagerInfo(manager_);

    Try();
    return 0;
}