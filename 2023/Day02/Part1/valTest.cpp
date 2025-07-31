#include <stdio.h>

int main()
{
    // int num = 10;   // 초기화
    // 스텍에 저장할 수 있는 공간을 할당 받았는데 거기 이름을 num1이라고 한다.
    // 타입은 변수의 크기를 뜻한다.
    // int num1;       // 변수선언 
    // num1 = 20;      // 대입
    // num1 = 30;
    // printf("int 크기 : %d\n", sizeof(int));
    //
    // char ch;        // 문자 타입
    // printf("ch 크기 : %d\n", sizeof(char));
    //
    // double d = 3.14;
    // printf("double 크기 : %d\n", sizeof(double));

    char ch = 0x7f;         // 16진법 0 ~ 9 A B C D E F
                            // == 0b 0111 1111 (8bit) 8 4 2 1 4비트 = nibble 
                            // 최상위 비트 = 부호 비트
    unsigned char ch1 = 0x7f;                            
    printf("ch : %x \t ch : %d\n", ch, ch);    
    printf("ch1 : %x \t ch1 : %d\n", ch1, ch1);    
    // 우리가 배정 받을 때는 1바이트 크기의 메모리 사이즈를 받는다
    // 실제 연산이 이루어지는 경우에는 1바이트도 INT - 4바이트로 바껴서 연산된다.
    // ch2 : ffffff9f 	 ch : -97
    // uch2 : 9f 	 uch2 : 159
    char ch2 = 0x9f;
    unsigned char uch2 = 0x9f;                            
    printf("ch2 : %x \t ch : %d\n", ch2, ch2);    
    printf("uch2 : %x \t uch2 : %d\n", uch2, uch2);    
                        // 0b 1001 1111 << 1 ==> 0b 1 0011 1110
    uch2 = uch2 << 1;   // 비트연산자 uch2를 왼쪽으로 1비트씩 옮겨라
    ch2 = ch2 << 1;
    printf("uch2 << 1 :  %x\n ch2 << 1 :  %x\n", ch2, uch2);   

    ch2 = 0x9f; 
    uch2 = 0x9f;
    ch2 = ch2 >> 1;
    uch2 = uch2 >> 1;
    printf("uch2 >> 1 :  %x\n ch2 >> 1 :  %x\n", ch2, uch2);  


    return 0;       
}