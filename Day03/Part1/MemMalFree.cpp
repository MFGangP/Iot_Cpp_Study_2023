#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char* MakeStrAdr(int len)
{
    char* str=(char*)malloc(sizeof(char)*len); 
    return str;
}

int main(void)
{
    char * str=MakeStrAdr(20);
    strcpy(str, "I am so happy~");  // strcpy 문자열 복사 - 매개변수 2개 첫번째 매개변수에 두번째 매개변수 값을넣는 함수
    cout<<str<<endl;
    free(str);
    return 0;
}