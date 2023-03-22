#include <stdio.h>

int main() 
{   /*
    // int num = 10;
    // printf("num : %d\n", num);
    // num = 20;
    // printf("num : %d\n", num);
    int num = 10; // 상수화 동시에 초기화
    printf("num : %d\n", num);
    // num = 20;
    int *p = &num; // 주소를 저장할 수 있는 포인터 변수(변수의 주소값), 
                    // &(주소연산자) 얘들은 기호
    printf("p에 저장된 값 : %p\n", p);
    printf("p가 참조하는 값 : %d\n", *p); // 데이터를 읽어와라
    *p = 20; // 얘는 간접 참조 연산자 - p라는 포인터가 가르키는 곳에 있는 값을 참조해라 
             // 데이터 값을 가져오고 싶을 때 쓰는 애 , 주소가 가르키는 값을 참조해라
    printf("p가 가리키는 곳의 데이터 값 : %d\n", *p);
    printf("num : %d\n", num);
    */

    const int num = 10;
    //num = 100;
    printf("num : %d\n", num);
    // 변수를 상수화 시켜놔도 포인터 변수로 바꾸는게 가능하다
    int* p= &num;
    *p = 100;
    printf("num : %d\n", num);

    int num1 = 100;
    int num2 = 200;
    // const가 맨 앞에 붙으면 포인터 변수의 데이터 값 상수화 
    const int* pa = &num1; 
    printf("pa : %p\n", pa);
    pa = &num2;
    printf("변경 후 pa : %p\n", pa);
    // *pa = 50;
    // 포인터 변수가 가지고있는 주소값 자체를 상수화 시키겠다.
    int* const pb = &num1;
    // pb = &num2;
    *pb = 70; // 주소값을 상수화 시킨거라서 값 변경은 가능
    return 0;
}
