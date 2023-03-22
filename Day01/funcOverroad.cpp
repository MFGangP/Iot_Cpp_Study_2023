#include <iostream> 

// 함수 오버로딩 다중정의
// C++은 매개변수의 개수로 함수를 찾아낸다.
void MyFunc(int num)
{
    std::cout<< "첫 번째 함수  : "<< num << "입니다"<<std::endl;
}

void MyFunc(int a, int b)
{
    int res = a + b;
    std::cout<<"두 수의 합은 "<< res <<"입니다"<<std::endl;
}

int main()
{
    MyFunc(6);
    MyFunc(6, 7);
    return 0;
}
