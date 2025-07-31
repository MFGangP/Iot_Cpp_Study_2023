#include <iostream>
using namespace std;

class Super{

    public:
        // void func1(){ cout << "Super::func1()" << endl; }
        // void func2(){ cout << "Super::func2()" << endl; }
        // 객체 포인터를 안쓰면 딱히 문제 없다 쓰니까 버츄얼을 쓰는거다.
        // virtual
        // 객체 타입에 맞춘 형태의 값이 출력 되더라.
        // 기준이 되는 자료형 자체가 객체 포인터에서 객체로 바뀌어버림
        virtual void func1(){ cout << "Super::func1()" << endl; }
        virtual void func2(){ cout << "Super::func2()" << endl; } // 자식 클래스의 객체를 읽어오더라
        void func3(){ cout << "Super::func3()" << endl; }
};

class Sub : public Super {
    
    public:
        void func1(){ cout << "Sub::func1()" << endl; }
        void func2(){ cout << "Sub::func2()" << endl; }
        void func3(){ cout << "Sub::func2()" << endl; }
        void func4(){ cout << "Sub::func4()" << endl; }
};
// 객체마다 가상함수 테이블이 만들어지고 Virtual 함수들이 그 안에 등록된다. 
// 이를 기반으로 불러와서 출력된다
int main()
{
    Super super;
    Sub sub;

    Super* sptr = new Sub;
    sptr->func1();
    sptr->func2();
    sptr->func3();

    delete sptr;
    return 0;
}
    /*
    Super super;
    Sub sub;

    super.func1();
    super.func2();
    super.func3();
    // 오버라이딩 - 부모 클래스를 덮어쓰고 자식 클래스가 튀어나온다.
    sub.func1();
    sub.func2();
    sub.func3();
    sub.func4();

    cout << endl;
    // 부모 클래스 Super타입의 포인터로 자식 객체를 가리킴
    // 객체를 가리키는 포인터 타입이 기준이 된다.
    Super* ps = new Sub; // 자식 객체를 부모 포인터로 연결한다.
    ps->func1(); // 포인터 자체가 부모 클래스라서 부모 클래스 결과(매서드)로 나옴
    ps->func2();
    ps->func3();

    delete ps;
    */