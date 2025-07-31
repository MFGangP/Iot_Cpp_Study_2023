#include <iostream>
using namespace std;

// 어디에도 속하지 않는 전역 변수
// 몇 번 째 만들어졌는지 확인하기 위해서
// 전역변수를 쓸 일이 있으면 static을 쓰라하는데
// static으로 선언되어있는 변수를 건드리려고 하면
// 선언되어있는 함수 내에서만 할 수 있다.
// 전역변수는 어디에서나 건드릴수 있으니까 이상한데서 건드릴수도 있음. 위험하다.
// 내가 원하는 데이터 값이 변경 될 소지가 많다.
int simObjCnt=0;
int cmxObjCnt=0;

class SoSimple
{
    public:
        SoSimple()
        {
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체" << endl;
        }
};

class SoComplex
{
    public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex &copy)
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }

};

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}
