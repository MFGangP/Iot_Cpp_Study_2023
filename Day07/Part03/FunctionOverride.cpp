#include <iostream>
using namespace std;

class First {

    public:        
        void MyFunc(){ cout << "FirstFunc" << endl; }
};

class Second : public First {

    public:
        void MyFunc(){ cout << "SecondFunc" << endl; }
};

class Third : public Second {

    public:
        void MyFunc(){ cout << "ThirdFunc" << endl; }
};

int main(void){
    Third * tptr = new Third(); // 자기 자신의 객체를 가리키는 형태
    Second * sptr = tptr; // 부모 클래스가 자식 클래스를 가리키는 형태
    First * fptr = sptr; // 객체 타입 포인터가 -> 자식클래스 가리키는 형태
    // 셋다 Third 얘를 가리킴 셋다 오버라이딩 된 결과가 나온다
    fptr->MyFunc(); // 포인터로 접근 할 때 애로우 씀, 매서드 호출
    sptr->MyFunc(); // 객체 포인터 자료형에 따라 접근 할 수 있는 범위가 정해진다.
    tptr->MyFunc(); // 읽어오는 대상이 달라짐 부모 객체 포인터를 가지고 자식 객체를 가리키더라도
                    // 나는 자식 데이터, 메서드를 가져오고싶다 하면 Virtual을 쓰는거다.
    delete tptr;
    return 0;
}