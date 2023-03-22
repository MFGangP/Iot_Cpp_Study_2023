#include <iostream>

int g = 0;
void func()
{
    printf("func() : %p\n", func);
}
int main()
{
    int n = 10; // 지역변수
    func();
    printf("local n : %p\n", &n);
    printf("global g : %p\n", &g);

    return 0;
}

/*
메모리 영역은 크게 나누면
1. 코드 세그먼트
2. 데이터 세그먼트

*/