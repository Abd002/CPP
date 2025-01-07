#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Employee one(12,"abd002",32.2);
    Employee two(23, "hossam", 1023.3);
    Employee *three = new Employee(54, "test", 23.4);

    one.print();
    two.print();
    three->print();


    return 0;
}


