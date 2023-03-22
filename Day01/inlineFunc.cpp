#include <iostream>

inline int SQUARE(int x) // 인라인 함수 판단은 컴파일러가 알아서 한다.
{
    return x*x;
}

int main(void)
{
    std::cout<<SQUARE(5)<<std::endl;
    std::cout<<SQUARE(12)<<std::endl;
    return 0;
}