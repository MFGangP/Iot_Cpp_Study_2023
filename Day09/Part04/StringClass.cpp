#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String // 클래스 생성
{
    private:    // 멤버변수 두개
        int len; // 문자열 길이
        char* str; // 문자열 처리 
    public:
        String(); // 디폴트 생성자
        String(const char* s); // 문자열을 받는 생성자
        String(const String& s); // 복사 생성자 - 입력이 객체의 참조형태
        ~String(); // 소멸자
        String& operator= (const String& s); //
        String& operator+= (const String& s); //
        bool operator== (const String& s); //
        String operator+ (const String& s); //

        friend ostream& operator<< (ostream& os, const String& s);
        friend istream& operator>> (istream& is, String& s);
};
// 어디 소속인지 표시
String::String() // 생성자
{
    len = 0; // 0 초기화
    str=nullptr; // 포인터 초기화 - 나는 아무것도 가리키는게 없다.
    // NULL - 초기화
}

String::String(const char* s) // 문자열이 오니까 포인터
{
    len=strlen(s)+1; // 문자열 길이 + 1
    str=new char[len]; // 동적할당
    strcpy(str, s); // 읽어온 문자열 복사
}

String::String(const String& s) // 문자열이 오니까 포인터
{
    len=s.len; 
    str=new char[len]; 
    strcpy(str, s.str); 
}


String::~String()   // 소멸자
{
    if(str!=NULL)
        delete []str;
}

String& String::operator=(const String& s)
{
    if(str!=NULL)
        delete []str; // 기존 문자열 소멸
    len=s.len;
    str=new char[len]; // 새로 동적할당
    strcpy(str, s.str);
    return *this;
}

String& String::operator+=(const String& s)
{
    len+=(s.len-1); // NULL 문자 하나 없애려고
    char* tempstr=new char[len]; // 전체 크기 할당
    strcpy(tempstr, str); // 기존 문자열 복사 
    strcat(tempstr, s.str); // 기존에 있는 문자열에 문자열을 붙이는 함수

    if(str!=NULL)
        delete []str;
    str=tempstr;
    return *this;
}

bool String::operator== (const String& s)
{
    return strcmp(str, s.str) ? false : true; // 삼항 연산자
    // 참이면 앞 거짓이면 뒤 
    // strcmp - compare 같으면 0 다르면 1
}

String String::operator+ (const String& s)
{
    char* tempstr=new char[len+s.len-1];
    strcpy(tempstr, str); // 복사
    strcat(tempstr, s.str); // 붙이기

    String temp(tempstr);
    delete [] tempstr;
    return temp;
}
// 전역 함수 오버로딩
ostream& operator<< (ostream& os, const String& s)
{
    os<<s.str; // 시프트 연산자 왼쪽을 오른쪽 만큼 이동
    return os; // 자기자신 리턴
}
// 전역 함수 오버로딩
istream& operator>> (istream& is, String& s)
{
    char str[100]; // 100개의 방을 가지고있는 str 배열
    is>>str; // 시프트 연산자 우측으로 이동
    s=String(str);
    return is;
}

int main()
{
    string str1 = "I like "; 
    string str2 = "string class"; 
    string str3 = str1 + str2;

    cout << str1 << endl; 
    cout << str2 << endl; 
    cout << str3 << endl;

    str1+=str2;
    if(str1==str3) 
        cout << "동일 문자열!" << endl;
    else
        cout << "동일하지 않은 문자열!" << endl;

    string str4;
    cout << "문자열 입력: ";
    cin >> str4;
    cout << "입력한 문자열 : " << str4 << endl;
    return 0;
}   