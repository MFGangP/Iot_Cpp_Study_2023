#include <iostream>
using namespace std;

class Ctest
{
    private:
        int num;
    public:
        Ctest(int n) : num(n)
        {
            cout << num << endl;
            cout << "Ctest Constructor" << endl;
        }
        void Func()
        {
            cout << "Ctest Func()" << endl;
        }
        // 선언하면 가상테이블에 등록, 런타임에 호출되는 함수가 결정된다.
        virtual void V_Func()   // 가상함수
        {
            cout << "Ctest V_Func()" << endl;
        }
        // 기초클래스 소멸자에 가상 소멸자를 넣으면 Sub클래스의 소멸자가 튀어나온다.
        virtual ~Ctest()    // 슈퍼클래스 소멸자
        {
            cout << "Ctest Destructor" << endl;
        }
};

class CtestSub : public Ctest
{
    private:
        int subn;
    public:
        CtestSub(int ctn, int csn) : Ctest(ctn), subn(csn)
        {
            cout << subn << endl;
            cout <<"CtestSub Constructor" << endl;
        }
        void V_Func()
        {
            cout << "CtestSub V_Func()" << endl;
        }
        ~CtestSub() // 서브클래스 소멸자
        {
            cout << "CtestSub Destructor" << endl;
        }
};

int main()
{
    // Ctest ct(10);
    // cout << "------------------------------------" << endl;
    // CtestSub cs(20, 30);
    // cout << "------------------------------------" << endl;
    // 상위 클래스(추상 자료형(클래스))객체 포인터로 하위 클래스 객체를 건드릴거다.
    // 상위 클래스 객체 포인터 타입으로 new를 통해 힙 영역 메모리 할당 받으면서
    // CtestSub 타입의 3, 33 이라는 값을 던져준다.
    Ctest * ps = new CtestSub(3, 33);
    // 얘만 딸랑 실행하면 소멸자가 안나온다. 우리가 직접 해제를 해줘야된다.
    // 실직적인 객체에 있는 애는 소멸 안되고 기초클래스 포인터만 해제된다.
    cout << "------------------------------------" << endl;
    delete ps; // Sub 클래스의 소멸자는 안나왔다. 자식 클래스 메모리 할당도 해제 해줘야됌.
    // 파생클래스의 객체에는 접근을 안해서 그렇다 - (부모)기초클래스 타입.
    // 자식 클래스의 소멸자가 가려져버려서 안나오는 것. 이 문제를 가상 소멸자로 해결하는것
    cout << "------------------------------------" << endl;
    return 0;
}