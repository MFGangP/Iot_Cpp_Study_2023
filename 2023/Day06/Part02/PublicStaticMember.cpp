#include <iostream>
using namespace std;

class SoSimple
{
    // 외부접근 가능
    public:
        static int simObjCnt;

    public: // 불필요하지만 변수와 함수의 구분을 목적으로 삽입하기도 함
        SoSimple()
        {
            simObjCnt++;
        }
};

int SoSimple::simObjCnt=0;

int main(void)
{
    // static은 클래스 멤버이기 때문에 클래스 이름을 통해서 멤버 변수에 바로 접근 
    cout << SoSimple :: simObjCnt << "번째 SoSimple 객체" << endl;
    SoSimple sim1;
    SoSimple sim2;
    
    // 이거는 객체를 생성해서 접근
    cout << SoSimple :: simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;

    return 0;
}
