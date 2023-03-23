#include <iostream>
#include <stdio.h>

enum week {
    sun = 0,
    mon = 1,
    tue = 2,
    wed = 3
    // 연속적으로 어떤 정수값이 이어질 때 쓰는 형태
    // 따로 떨어져있는 값을 굳이 열거할 필요가 없다.
};

int main()
{
    printf("%d\n", sun);
    printf("%d\n", mon);
    printf("%d\n", tue);
    printf("%d\n", wed);
    return 0;
}