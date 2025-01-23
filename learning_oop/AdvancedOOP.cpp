#include <iostream>

using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    float add(float a, float b)
    {
        return a + b;
    }
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

class Animal
{
public:
    virtual void sound()
    {
        cout << "Sound of animal \n";
    }
};
class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Sound of cat \n";
    }
};
class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Sound of Dog\n";
    }
};

class Vehicle
{
public:
    void start()
    {
        cout << "start from vehicle\n";
    }
    virtual void move()
    {
        cout << "move from vehicle\n";
    }
};
class Car : public Vehicle
{
public:
    void move() override
    {
        cout << "move from Car\n";
    }
    void start()
    {
        cout << "start from car\n";
    }
};
class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape()
    {
        cout << "Destructor of Shape\n";
    }
};
class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "draw from Circle\n";
    }
    ~Circle()
    {
        cout << "Destructor of Circle\n";
    }
};
class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Draw from rectangle\n";
    }
};

class Person
{
public:
    virtual void introduce()
    {
        cout << "introduce function from preson\n";
    }
};
class Student final : public Person
{
public:
    void introduce() final override
    {
        cout << "introduce function from student\n";
    }
};
/*
// ❌ Attempting to inherit from final class Student (Compiler Error)
class Graduate : public Student {
public:
    // ❌ Attempting to override final function introduce() (Compiler Error)
    void introduce() override {
        std::cout << "Hi, I am a Graduate Student." << std::endl;
    }
};
*/

class LibraryItem
{
public:
    virtual void displayInfo()
    {
        cout << "displayInfo from base\n";
    }
};
class Book : public LibraryItem
{
public:
    void displayInfo() override
    {
        cout << "DisplayItem from Book\n";
    }
    void borrow()
    {
        cout << "first borrow\n";
    }
    void borrow(string a)
    {
        cout << a << endl;
    }
};
class DVD : public LibraryItem
{
public:
    void displayInfo() override
    {
        cout << "DisplayItem from DVD\n";
    }
};
class Magazine : public LibraryItem
{
public:
    void displayInfo() override
    {
        cout << "DisplayItem from Magazine\n";
    }
};

void Try(void)
{
    Calculator calc;
    cout << calc.add(1, 2) << endl;
    cout << calc.add((float)1.5, (float)2.5) << endl;
    cout << calc.add(1, 2, 3) << endl;

    Cat cat;
    cat.sound();

    Animal *ptr = new Cat();
    // if u remove virtual from Animal class it will print Sound of Animal
    ptr->sound();

    Vehicle v;
    Car c;

    // STATIC BINDING (Compile-time Binding)
    std::cout << "Static Binding Example:" << std::endl;
    v.start(); // Calls Vehicle's start() (Determined at Compile-time)
    c.start(); // Calls Car's start() (Determined at Compile-time)

    // DYNAMIC BINDING (Runtime Binding)
    std::cout << "\nDynamic Binding Example:" << std::endl;
    Vehicle *vPtr = &c; // Base class pointer to derived class object
    vPtr->start();      // Calls Vehicle's start() (Static Binding - Not Virtual)
    vPtr->move();       // Calls Car's move() (Dynamic Binding - Virtual Function)

    {
        Shape *circle = new Circle();
        delete circle;
    }

    Shape **Sptr = new Shape *[2];
    Sptr[0] = new Circle();
    Sptr[1] = new Rectangle();
    Sptr[0]->draw();
    Sptr[1]->draw();
    delete Sptr[0];
    delete Sptr[1];
    delete[] Sptr;

    Person *student = new Student();
    student->introduce();

    LibraryItem *libraryItem[] = {new Book(), new DVD(), new Magazine()};
    for (auto it : libraryItem)
    {
        it->displayInfo();
    }
    ((Book *)libraryItem[0])->borrow();
    ((Book *)libraryItem[0])->borrow("abd002");

    return;
}