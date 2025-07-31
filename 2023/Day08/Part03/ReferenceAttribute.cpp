#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc() {cout << "FirstFunc()" <<endl;}
    virtual void SimpleFunc() {cout << "First's SimpleFunc()" << endl;}
};

class Second : public First
{
public:
    void SecondFunc() {cout << "Second Func()" << endl;}
    virtual void SimpleFunc() {cout << "Second's SimpleFunc()" << endl;}
};

class Third : public Second
{
public:
    void ThirdFunc() {cout << "ThirdFunc()"<< endl;}
    virtual void SimpleFunc() {cout << "Third's SimpleFunc()" << endl;}
};

int main()
{
    // . 객체를 통한 데이터 참조
    // -> 포인터를 통한 참조
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    // 원래는 참조하는 포인터 기준
    // Virtual 함수 - 객체 기준으로 바뀜
    obj.SimpleFunc();
    // Second 참조자 부모 -> 자식
    Second & sref = obj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();
    // First 참조자 부모 -> 자식
    First & fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();
    return 0;
}