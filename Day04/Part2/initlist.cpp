#include <iostream>
using namespace std;

/*
콜론 초기화가 필요한 경우 
1. 상수 멤버 변수
2. 객체 멤버 변수
3. 참조 멤버 변수
(4. 멤버 변수(가능함))
*/
class ConstSome   
{
    public:
        const int val; // 상수 멤버 변수
        ConstSome(int n) : val(n) 
        {

        }
        void printval()
        {
            cout<<val<<endl;
        }
};
class RefSome
{
    public:
        int &ref;   // 참조 멤버 변수
        RefSome(int n) : ref(n)
        {
        }
        void printval()
        {
            cout<<ref<<endl;
        }
};
class PositionSome // 객체 멤버 함수
{    
    public:
        int x, y;
        PositionSome(int ax, int ay)
        {
            x = ax;
            y = ay;
        }
};
class ObjSome
{
    public:
        // PositionSome 타입
        PositionSome pos;   // 객체 멤버 변수
        // pos라는 객체에 저장 되야한다.
        ObjSome(int ax, int ay) : pos(ax, ay){}
        void printfval()
        {
            cout<<pos.x<<" "<<pos.y<<endl;
        }
};

int main()
{
    ConstSome c(10);
    c.printval();
    RefSome r(20);
    r.printval();
    ObjSome o(10, 10);
    o.printfval();
    return 0;
}