#include <iostream>
int Adder(int num1=1, int num2=2); // 이게 아래에 있으면 위에서 순서대로 읽어내려오니까 불가능
// 함수 선언

int main(void)
{
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(5)<<std::endl;
    std::cout<<Adder(3, 5)<<std::endl;
    return 0;
}

int Adder(int num1, int num2) // 디폴트 값은 함수의 선언 부분에서만 표현할 수 있다.
{
    return num1+num2;
}
