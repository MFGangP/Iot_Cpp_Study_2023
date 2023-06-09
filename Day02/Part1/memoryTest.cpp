#include <iostream>
int g = 0;

/*
메모리 영역은 크게 나누면
    동적 데이터
        힙
    정적 데이터
    코드

1. 코드 세그먼트
2. 데이터 세그먼트

*/
void func()
{
    printf("func() : %p\n", func);
}
int main()
{
    int n = 10; // 지역변수
    static int c;
    const int d = 10;
    char ary[10] = "hi,myname";

    func();
    printf("local n : %p\n", &n);
    printf("global g : %p\n", &g);
    printf("static c : %p\n", &c);
    printf("const d : %p\n", &d);
    printf("array : %p\n", &ary);

    return 0;
}