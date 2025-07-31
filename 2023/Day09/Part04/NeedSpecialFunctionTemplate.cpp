#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}

int main(void)
{
    cout<< Max(11, 15)          << endl; // 거짓
    cout<< Max('T', 'Q')        << endl; // 참
    cout<< Max(3.5, 7.5)        << endl; // 거짓
    cout<< Max("Simple", "Best")<< endl; // 첫 글자 비교
    return 0;
}