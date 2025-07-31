// 계산기 클래스 생성
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#ifndef _Calculator_H
#define _Calculator_H

using namespace std;

class NumFormula{

	private:
       char* temp;

	public:
        // 동적 할당
		NumFormula(const char* atemp)
		{
			temp = new char[strlen(atemp) + 1];
			strcpy(temp, atemp);
		}
		// 소멸자
		~NumFormula(){
			delete temp;
		}
		// 함수 선언
		void Calculate(const char* temp);
};          


#endif