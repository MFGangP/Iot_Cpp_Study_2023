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
    protected:
    // 멤버 함수(= 메소드) : 기능
    public: 
        // 생성자 = 멤버 변수를 초기화 시키는 기능
        // a = 매개변수 접두어
        // 리터럴 = 상수
        // 문자열 const 상수화 해줘야 된다.
        void set(char aId, int aAge, const char *aName)
        {
            // SET 이라는 함수의 입력값으로 초기화 하는거다.
            // char 를 받으면 문자로 인식하기 때문에 ''를 해줘야한다.
            id = aId;
            // 기본 자료형들만 대입 연산자가 가능하다.
            // 연산자 오버로딩을 해야 덮어씌울 수 있다.
            // strcpy
            age = aAge;
            strcpy(name, aName);
            // 비주얼 스튜디오 strcpy(name, 10, aName);       
        };
        void get()
        {
           cout<<"아이디 : "<<id<<endl;
           cout<<"나이 : "<<age<<endl;
           cout<<"이름 : "<<name<<endl;
        };
};

int main()
{
    MyClass Me;
    Me.set('1', 27, "Hyeon");
    Me.get();
    return 0;
}