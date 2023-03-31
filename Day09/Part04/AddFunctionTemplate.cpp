#include <iostream>
using namespace std;

template <typename T>
// 함수 틀
// 함수 출력, 함수 이름, 대표 자료형, 인자
// 입력, 출력 둘 다 있다.
// 매개변수 타입이 다르다.
T Add(T num1, T num2)
{
    return num1+num2;
}

// int main(void)
// {   // 함수 명, 자료형, 인자
//     cout << Add<int>(15, 20)        << endl;
//     cout << Add<double>(2.9, 3.7)   << endl;
//     cout << Add<int>(3.2, 3.2)      << endl;
//     cout << Add<double>(3.14, 2.75) << endl;
//     return 0;
// }

int main(void)
{   // 함수 명, 자료형, 인자
    cout << Add(15, 20)        << endl;
    cout << Add(2.9, 3.7)      << endl;
    cout << Add(3.2, 3.2)      << endl;
    cout << Add(3.14, 2.75)    << endl;
    return 0;
}