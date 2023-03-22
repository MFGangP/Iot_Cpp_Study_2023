#include <iostream>
#include "../../Program Files (x86)/Windows Kits/10/Include/10.0.22621.0/ucrt/stdio.h"

int main()
{
	char ch[5] = "hong"; // 배열선언 뒤에 null 들어감
	// 문자 하나씩 저장하면 다 넣어도 상관 없음
	printf("char 크기 : %d\n", sizeof(char));
	
	printf("%s\n", ch[4]);
	//ch[0] = 'a';
	return 0;	
}