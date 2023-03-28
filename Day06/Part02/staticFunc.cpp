#include <iostream>
using namespace std;

class StaticTest
{
    private:
        static int a;   // 멤버변수의 static
        int b;

    public:
        StaticTest();
        static void SetData(int aa); // 멤버함수의 static

        void print();
};

int StaticTest :: a = 10;   // static 멤버변수 초기화

StaticTest :: StaticTest() // 일반 멤버 변수 초기화
{
    this->b = 20;   // this는 객체 자신에 있는 b 값
}

void StaticTest :: SetData(int aa)
{
    // this-> a = 30; 이거 안됌
    // StaticTest은 클래스 것. static 멤버는 객체 포인터로 접근 할 수 없다.
    // 객체가 소유하는게 아니기 때문에
    // this 포인터를 못쓴다.
    a = aa; 
}

void StaticTest :: print()
{
    cout << "a : " << a << ", " << "b : " << b << endl;
}
int main()
{
    StaticTest s1, s2;
    s1.print();   
    s2.print();   

    s1.SetData(30);
    s1.print();

    s2.SetData(50);
    s2.print();

    StaticTest :: SetData(100);
    s1.print();
    s2.print();

    return 0;
}