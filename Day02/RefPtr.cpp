#include <iostream>
using namespace std;

int main()
{
    int num = 12;
    int* ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int* (ptr) = ptr;
    int** (dpref) = dptr;


    cout<<ref<<endl;
    cout<<*ptr<<endl;
    cout<<**dpref<<endl;

    return 0;
}