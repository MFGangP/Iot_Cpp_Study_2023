#include <iostream>
#include <stdio.h>
/*
사용자 정의 자료형인 구조체 - 내가 만든 자료형
*/
struct human{       // 이안에 있는 애들은 맴버 변수
    char name[20];  // 20바이트로 이루어진 name이라는 변수
    int age;        // 나이를 집어넣을 수 있는 변수
    // 여기서 초기화 해봐야 의미가 없다.
}; // 구조체 끝에는 ;을 넣어줘야한다.
    // 이 자체로는 메모리에 할당 안되어있음.
    // 필요한 걸 한 곳에 모아놓은 것
int main()
{
    // char h; 
    struct human h = { "홍길동" , 23 }; // human이라는 구조체 타입에 h라는 변수를 선언
    // 여기서 변수 초기화 해야된다. 할 때는 중괄호를 써서
    // 이렇게 만들어야 메모리에 할당된다.
    printf("이름 : %s\n", h.name);
    printf("나이 : %s\n", h.age);

    return 0;
}