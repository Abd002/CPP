#include <iostream>
using namespace std;

void print(string s){
    cout<<s<<endl;
}

void print(int x){
    cout<<x<<endl;
}

void print(double x){
    cout<<x<<endl;
}

int main(){

    print("test");
    print(5);
    print(3.14);

    
    return 0;
}
