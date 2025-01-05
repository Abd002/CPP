#include <iostream>
using namespace std;

#define ROW_SIZE 5
#define COLUMN_SIZE 10

int main() {

    int **arr = new int*[ROW_SIZE];
    for(int i=0;i<ROW_SIZE;i++){
        arr[i]=new int[COLUMN_SIZE];

        for(int j=0;j<COLUMN_SIZE;j++){
            arr[i][j]=i*ROW_SIZE+j;
        }
    }

    for(int i=0;i<ROW_SIZE;i++){
        for(int j=0;j<COLUMN_SIZE;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    

    for(int i=0;i<ROW_SIZE;i++){
        delete [] arr[i];
    }
    delete []arr;
    return 0;
}


