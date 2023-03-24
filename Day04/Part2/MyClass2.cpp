#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 클래스 멤버 변수에 접근할 수 있는 방법은 3가지로 표현된다. (은닉)
class MyClass {
    // 멤버변수 : 속성
    private: // 외부에서 접근 불가, 값을 바꾸려면 멤버 함수로 바꾸는 거만 가능
        char id;
        // char id = 10; 이런건 안된다.
        // 속성 값을 이렇게 초기화 하는건 의미가 없다.
        // 객체를 생성 할 때마다 다 달라야된다.
        // 대입 연산자 써서 그냥 넣어라
        int age;
        char name[10];
    public: 
        // 생성자 = 멤버 변수를 초기화 시키는 기능
        MyClass(char aId) : id(aId){}
        MyClass(char aId, int aAge): id(aId), age(aAge){}
        // MyClass(char aId, int aAge, const char *aName) : id(aId), age(aAge){
        //          };
        // 생성자가 호출 될 때 바로 초기화 하는 방법
        MyClass(char aId, int aAge, const char *aName)  : id(aId), age(aAge){ strcpy(name ,aName); }
        // 생성자 호출되고 나서 실행 될 때 초기화 된다.

        // a = 매개변수 접두어
        // 리터럴 = 상수
        // 문자열 const 상수화 해줘야 된다.
        // 비주얼 스튜디오 strcpy(name, 10, aName);      
        void get()
        {
            if(age == 0 and name == 0)
            {
                cout<<"아이디 : "<<id<<endl;
            }
            else if(name == 0)
            {
                cout<<"아이디 : "<<id<<endl;
                cout<<"나이 : "<<age<<endl; 
            }
            else
            {
            cout<<"아이디 : "<<id<<endl;
            cout<<"나이 : "<<age<<endl;
            cout<<"이름 : "<<name<<endl;
            }
        }
/*
MyClass(char aId, int aAge, const char *aName); 생성자 원형

MyClass::MyClass(char aId, int aAge, const char *aName){
    id = aId;
    age = aAge;
    strcpy(name, aName);
} 생성자 정의
*/
};

int main()
{
    // MyClass Me('1');
    // Me.get();
    // MyClass Me('1', 27);
    // Me.get();
    MyClass Me('1', 27, "Hyeon");
    Me.get();

    return 0;
}