#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

#include "Calculator.h"

using namespace std;

double x; // 첫번째 값
double y; // 두번째 값
const char* cper; // 기호
// 연산자 기호 선언
const char* separator_add = "+";
const char* separator_sub = "-";
const char* separator_mul = "*";
const char* separator_div = "/";

// 함수 정의
// 자료형, 함수 소속::함수 이름
void NumFormula::Calculate(const char* temp)
{
    string str = temp; // 나누기 위해 string 타입 str 객체 생성

    int cur_position = 0; // 탐색 시작 위치
    int position; // 기호 등장 위치
    // find는 찾는 값이 있으면 문자열 앞에서부터 검색을 시작해 
    // 검색 문자열이 시작되는 위치를 반환. 아니면 string::npos(4294967295) 반환.
    if (str.find(separator_add) != string::npos) // 쓰레기 값이 아니라면
    {
        // 기호 cper에 저장
        cper = separator_add;
        // 기호를 문자열에서 찾아서 쓰레기 값이 안나오는 동안
        while ((position = str.find(separator_add, cur_position)) != string::npos)
        {
            // len는 첫번째 문자열 길이 - 기호 등장 위치 - 시작 위치
            int len = position - cur_position;
            // 배열 결과 값은 커서 위치 부터 len 까지
            string result = str.substr(cur_position, len);
            // cout << result << endl;
            x = stod(result); // 첫번째 숫자 x에 대입
            // 커서 시작 위치 기호 뒤로 한칸 밀기 - 2번째 숫자 인식 시작점
            cur_position = position + 1;
        }
		// 두번째 문자열에는 기호가 없기 때문에 쓰레기 값이 나온다.
        // 배열 결과값 커서 위치부터 끝까지
        string result = str.substr(cur_position);
        // 두번째 값 y에 대입
        y = stod(result);
		// 계산 실행
        cout << "= " << x + y << endl << endl;
    }
    else if (str.find(separator_sub) != string::npos)
    {
        cper = separator_add;

        while ((position = str.find(separator_sub, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << "= " << x - y << endl << endl;
    }
    else if (str.find(separator_mul) != string::npos)
    {
        cper = separator_add;

        while ((position = str.find(separator_mul, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << "= " << x * y << endl << endl;
    }
    else if (str.find(separator_div) != string::npos)
    {
        cper = separator_add;

        while ((position = str.find(separator_div, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << "= " << x / y << endl << endl;
    }
}
