#include <iostream>

int add(int n1, int n2)
{
    return n1 + n2;
}

int sub(int n1, int n2)
{
    return n1 - n2;
}
// 동일한 타입의 여러가지 함수가 구현되어 있을 때 함수 포인터 필요
// 함수의 형태가 똑같아야한다.
int main()
{
    // 값 저장할 빈칸
    int res;
    // 함수 포인터 선언
    // 출력 함수이름(입력)
    int (*fp)(int, int);
    fp = add;
    res = fp(10, 20);
    printf("%d\n", res);

    fp = sub;
    res = fp(20, 10);
    printf("%d\n", res);
    // 함수 이름만으로 주소값이 나오는걸 보면 함수도 주소값이라는걸 알 수 있다.
    printf("%p\n", add);
    printf("%p\n", sub);

    return 0;
}