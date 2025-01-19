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
void modify(int &x) {  // x is a reference parameter
    x = 10;  // Modifies the original variable
}
```

# OOP

- if u create static member don't forget to define it in .cpp or it will case linker error
- `int getId() const;` guarantees not to modify the object
- **deep copy** : creating a new object and allocating new memory for it
- **shallow copy** : only copies the pointer, both objects share the same memory
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
