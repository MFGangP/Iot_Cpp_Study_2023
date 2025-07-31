#include <iostream>
using namespace std;

class SoSimple
{
    private:
        static int simObjCnt;
    // 클래스 소속. 객체 별로 할당이 안된다.
    // 맴버 변수지만 정적 영역에 할당 된다.
    public:
        SoSimple()
        {
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체" << endl;
        }
};
int SoSimple :: simObjCnt=0;
// 클래스 내에 있는 static 함수는 이렇게 초기화 해야된다.
// 생성자는 객체가 생성될 때 불러오는데 객체 생성과 상관없는 애라서
// 생성자에서 초기화 하는게 아니다.
// 객체 별로 할당되는게 아니고 모두 같이 공유한다. 
class SoComplex
{
    private:
        static int cmxObjCnt;
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

int SoComplex :: cmxObjCnt=0;

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}
