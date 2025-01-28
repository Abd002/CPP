# CPP

## overload functions

## use dynamic arrays like that

- when creating 2D or any thing u r dealing with pointer nothing else

```
int *arr = new int[5];
/*
    int **arr = new int*[5];
*/
delete[] arr;
```

- dealing with **reference parameter**

```
void modify(int &x) {  // x is a reference/alias parameter
    x = 10;  // Modifies the original variable
}
```

# OOP

- if u create static member don't forget to define it in .cpp or it will case linker error
- const member function`int getId() const;` guarantees not to modify the object and **when u create const instance u can only use const methods**
- **deep copy** : creating a new object and allocating new memory for it
- **shallow copy** : only copies the pointer, both objects share the same memory
- use structs when u need
  1. simple data container.
  2. Direct access to all members is acceptable. Less secure (direct modification)
- You cannot dynamically allocate an array of Book objects using `new Book[3]` when the Book class only has a **parameterized constructor** (without a default constructor).
  - ```c
    Book(): title(""), price(0.0) {}; // ✅ Default constructor
    Book(const std::string &title, double price); // Parameterized constructor
    ```
- `Person *student= new Student();` notice that u cann't access Student methods unless u convert it using this `((Student*)student)->(studentMethods)`
- u can disable default copy constructor and assignment using

  ```c
  // Delete Copy Constructor and Copy Assignment Operator or u can make it default
  MyString(const MyString&) = delete;
  MyString& operator=(const MyString&) = default;
  ```

- ## **copy constructor**
  syntax : `DynamicMatrix::DynamicMatrix(const DynamicMatrix &other)`
- ## **Access Specifier**
  1. `public` -> accessible from anywhere
  2. `private` -> only accessible inside the class itself (or by friends of the class).
  3. `protected` -> accessible within the class and by derived classes (subclasses).
- ## **friend**

  - used to allow a specific function or class to access the private and protected members of another class.

  ```c
    class MyClass {
    private:
      int x;
    public:
        MyClass() : x(10) {}
        //classB can access every private and protected members or methods
        friend classB;

        //this function is implemented out of class and can acces ...
        //write class if u use object of another class but here u can delete it
        friend void printX(const class MyClass& obj);
    };
  ```

- ## **Destructors**
  - syntax ~className();
  - used for deallocates the memory to prevent memory leaks.
  - when u creat an instance it will be called when object goes out of scope -> stack allocation.
  - if u create the object using dynamic allocation `DynamicArray *arr = new DynamicArray(5);` it will be called after using `delete arr;` -> heap allocation.
  - **dealing with Dynamic allocate** `Shape* shapePtr = new Circle();`
    - When a base class destructor is non-virtual, only the base class destructor is called when deleting a derived class object through a base class pointer.
    - The derived class’s destructor never executes, leading to incomplete destruction and potential memory leaks.
- ## **method chaining**
  - what is this : `account.deposit(1000).withdraw(200).`
  - to use it then `deposit and withdraw` methods should return refernce to the same class ex:`BankAccount &BankAccount::withdraw(int value)`
- ## **<u>Encapsulation</u>**
  - Marking data members as private to prevent direct modification from outside the class.
  - Providing public getter and setter methods to control access to private data members.
- ## **<u>Abstraction</u>**
  - abstracted class cann't be called if it using **pure virtual function** will cause error
  - best deal with abstracted class is to make pointer of it and access all other derived classes
  - u must make Destructor as virtual in abstracted class **in cass u deal with it's pointer** it will call sub-class Destructor also
- ## **Virtual**
  - If you don't declare a function as virtual in the base class, will use compile-time (static) binding, meaning the function that gets called is determined by the type of the pointer/reference, not the actual object.
  - **pure Virtual** `virtual void pureVirtualFunction() = 0;` -> then u must implement this function in it's sub-classes
  - **default Virtual** `virtual void pureVirtualFunction(){};`
  - when u implement this function in sub-classes use this syntax `void pureVirtualFunction() override {}`
- ## **<u>Polymorphism</u>**
  - **Runtime Polymorphism** (**dynamic binding**)
    - using **virtual** and and **method overriding** for allawing **dynamic binding**, late binding
    - The virtual keyword tells the compiler to use runtime polymorphism, meaning the function that gets called depends on the actual object type, not the pointer type.
    - `vPtr->move(); calls Car::move()` vPtr is base class pointer
    - Use dynamic binding when function behavior should be overridden in derived classes
    - C++ uses a mechanism called vtable (virtual table) and vptr (virtual table pointer) to determine which function to call at runtime.
      - The compiler creates a vtable (virtual table) for each class that has at least one virtual function.
      - Each object of a class containing virtual functions has a hidden pointer (vptr) pointing to the class's vtable.
      - The vtable is an array of function pointers.
      - Each class has its own vtable containing function addresses for its virtual functions.
      - If a derived class overrides a virtual function, the vtable entry is updated to point to the derived class function.
  - **Compile-Time Polymorphism** (**Static Binding**)
    - (**overload**) functions have the same name but different parameter lists (different number or type of parameters)., early binding
    - When the program is compiled, the compiler looks at the function call and determines which version of the overloaded function to invoke based on the arguments' number and types.
    - static binding ignores object type.
    - `v.start(); calls Vehicle::start().`
    - Use static binding when function behavior should not change based on object type
- ## **Types of <U>Inheritance</u>**

  - if u choose inheritance type otherwise public u cann't do this `Employee* emp = new Manager("Alice", 40, "HR"); // ❌ ERROR:` because : Manager is not publicly related to Employee

  - | Inheritance Type | Effect on `public` Members of Base    | Effect on `protected` Members of Base | Effect on `private` Members of Base |
    | ---------------- | ------------------------------------- | ------------------------------------- | ----------------------------------- |
    | `public`         | **Remain public** in derived class    | **Remain protected** in derived class | **Not inherited (inaccessible)**    |
    | `protected`      | **Become protected** in derived class | **Remain protected** in derived class | **Not inherited**                   |
    | `private`        | **Become private** in derived class   | **Become private** in derived class   | **Not inherited**                   |

- ## **Final Specifier**
  - **final with Classes** : Prevents further inheritance of a class.
    `class ClassName final {};`
  - **final with Functions** : Prevents a virtual function from being overridden in any derived class.
    `virtual void functionName() final;`
  - missuse of it will cause Compiler Error
- ## **noexcept**
  - `MyString(MyString &&other) noexcept` indicate that a function does not throw any exceptions.
  - used to dealing with move assignment operator and move constructor
  - make diffrence between copy and move assignment
    ```c
      MyString s2 = std::move(s1);//it will call move constructor
      MyString s2 = (s1);//will call copy constructor
    ```
- ## **assignment operator**

  - syntax : `DynamicMatrix& operator=(const DynamicMatrix &other);`
  - `DynamicMatrix&` : commonly used in assignment operators to support chained assignments.
    ex. a = b = c ;
  - steps used :
    1. first check if it self assignment
    2. free old memory if exist
    3. copy data as required (deep or shallow)
    4. return `*this` which will return reference to current object

- ## **L-value and R-value**

  - `const std::string&` allows binding to both lvalues and rvalues because of **const**

    - ```c
      Car(std::string& make, std::string& model, int year)
      Car myCar("Toyota", "Camry", 2022);  // ❌ ERROR rvalue

      std::string carMake = "Toyota";
      std::string carModel = "Camry";
      Car myCar(carMake, carModel, 2022);  // ✅ Works, because carMake is an lvalue
      ```

  - fix it with **const** and it will work with both because : because r-values don't need to be modified.
  - ### **Lvalue**
    - object that has a name
    - can be referenced `int& ref = a;`
  - ### **Rvalue**
    - temporary value that doesn’t persist
    - can be referenced `int&& ref = 10;` called Rvalue references used with **move**
    - `x + 5` is Rvalue

- ## **Move**
  - means transferring ownership of a resource from one object to another without copying it.
  - ```c
    std::string s = "Hello";
    std::string t = std::move(s);  // Moves data to 't' call move constructor
    std::cout << s;  // ❌ Undefined behavior! (s is now empty)
    ```
  - in assignment operator in string class we will use Rvalue references with **move** to move data

# Exception Handling

- using **try-catch** block to catch any **throw** happens in the programm otherwise it will **terminate**
- use throw to rise exception of specific object then u can catch this object
- you can throw any type of object and catch any type -> use it to catch specific exception
- throw like return it exit the function immediatlty
- u can chain any number of catch block to catch specific type
- example

  ```cpp
  class BankException : public std::exception {
  public:
      virtual const char* what() const noexcept {
          return "Bank exception occurred!";
      }
  };

  /*
  in code u will throw BankException
  if it in try-catch block it will be caught
  */
  try {}catch(const BankException&e){}catch(const exception&e){}
  ```

- note that if u made class of that inherit from std::exception and u write in what() function then u could catch `const exception&e` and it will print the string in what() function of the class u made -> dynamic binding

# Overload Operators

- overload the input and output stream
  ```cpp
    // ostream for cout
    // use friend so u can use it with cin >> c1 -> not c1.operator>>(cin);
    friend istream &operator>>(istream &in, Complex &c)
    {
        in >> c.real >> c.imaginary;
        return in;
    }
  ```
- overload any other operator like this
  `DynamicMatrix& operator=(const DynamicMatrix &other){}` and u can use any type u want ex -> `DynamicMatrix& operator=(const int x){size = x;return *this;}`
- don't forget to return

# Functor

- function object : any object that can be called like a function. This is achieved by **overloading the operator() in a class**.
- Compatibility with STL
- ```cpp
  class MyFunctor {
  public:
      void operator()(int x) {
          std::cout << "This is a functor, called with " << x << std::endl;
      }
  };
  // will be called like that {MyFunctor functor; functor(5);}
  ```

# Predicate

- function or function object (functor) that returns a boolean value
- typically passed to algorithms such as `find_if`, `sort`, or `remove_if` to filter or evaluate data based on a condition. -> using this methods with list is better than vector
- can be **Lambda Function Predicate**

# Templates

- feature that allows you to write generic and reusable code.
- Function Templates
- Class Templates
- Template Specialization `template <>` then `ReturnType functionName<Type>() {}`
- Multiple Template Parameters
- Default Template Arguments
- Variadic Templates
- Template Metaprogramming -> recursive template that computes the factorial of a number at compile time.
- examples

  ```cpp
    template <typename T, typename U = int>
    class ClassName {
        T data;
    public:
        ClassName(T value) : data(value) {}
    };//to make object use Classname<dataType>test;

    // Generic template for function
    template <typename... Args>
    void print(Args... args) {
        (cout << ... << args) << endl;  // C++17 fold expression
    }
    // Specialization for type `char*` (C-style string)
    template <>
    const char* print<char*>(const char* value) {
        return "This is a string!";
    }

    template <int N>
    struct Factorial {
        static const int value = N * Factorial<N - 1>::value;
    };
    template <>
    struct Factorial<0> {
        static const int value = 1;
    };
    //call it using Factorial<5>::value
  ```
