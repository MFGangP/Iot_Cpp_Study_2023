#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

#include "Calculator.h"

using namespace std;

char temp[50];

int main()
{
	cout << "Calculator Console Application\n\n" << endl;
	cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b\n" << endl;
	cout << "Press \"ctrl + c\" to exit the progtram\n" << endl;

	while (true) {
		cout << "input >> ";
		cin >> temp; // temp 배열에 입력 문자열 넣기 

		NumFormula F(temp);	// NumFormula클래스 F 객체 생성 입력값은 temp 문자열
		F.Calculate(temp); // 클래스 내 함수 실행.
	}
    return 0;
}