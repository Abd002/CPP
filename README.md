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
- const member function`int getId() const;` guarantees not to modify the object
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
- ## **copy constructor**
  syntax : `DynamicMatrix::DynamicMatrix(const DynamicMatrix &other)`
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

  - fix it with **const** and it will work with both
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
    std::string t = std::move(s);  // Moves data to 't'
    std::cout << s;  // ❌ Undefined behavior! (s is now empty)
    ```
  - in assignment operator in string class we will use Rvalue references with **move** to move data
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
        friend void printX(const MyClass& obj);
    };
  ```

- ## **Destructors**
  - syntax ~className();
  - used for deallocates the memory to prevent memory leaks.
  - when u creat an instance it will be called when object goes out of scope -> stack allocation.
  - if u create the object using dynamic allocation `DynamicArray *arr = new DynamicArray(5);` it will be called after using `delete arr;` -> heap allocation.
- ## **method chaining**
  - what is this : `account.deposit(1000).withdraw(200).`
  - to use it then `deposit and withdraw` methods should return refernce to the same class ex:`BankAccount &BankAccount::withdraw(int value)`
- ## **Encapsulation**
  - Marking data members as private to prevent direct modification from outside the class.
  - Providing public getter and setter methods to control access to private data members.
