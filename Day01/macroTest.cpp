#include <iostream>

#define SQUARE(x) x * x  // 매크로 함수
// 컴파일러가 전처리 과정에서 함수를 인식했기 때문에 
// 함수를 찾으러 점프 안하고 바로 실행 된다. 속도가 빠름, 단점은 용량 먹고있음
#define SUM(x, y) x + y
#define SQUARE1(x) (x) * (x) // 사칙연산 우선 순위 지정
void func()
{

}

int main()
{
    std::cout<<SQUARE(10 + 1)<<std::endl; // 10 + (1 * 10) + 1 사칙연산 우선 순위 때문에 값이 바뀐다.
    std::cout<<SUM(10.1, 20.2)<<std::endl;
    std::cout<<SQUARE(10.1 + 20.2)<<std::endl;
    std::cout<<SQUARE1(10 + 20)<<std::endl;

    return 0;
}