#include <iostream>
using namespace std;

class Super{
    public:
        Super(){
            cout << "Super()" << endl;
        }
        ~Super(){
            cout << "~Super()" << endl;
        }
};
class Sub : public Super {
    public:
        // 호출이 되기는 얘가 먼저 되는데
        // 상속을 받았기 때문에 부모 클래스의 생성자를 호출하러 들렀다온다
        // 호출과 실행의 개념은 다르다.
        Sub(){
            cout << "Sub()" << endl;
        }
        // 소멸자는 자식 클래스가 먼저 죽고
        // 부모 클래스가 나중에 죽는다.
        // 스택의 개념을 그대로 받는다.
        ~Sub(){
            cout << "~Sub()" << endl;
        }
};

int main()
{
    cout << "Start" << endl;
    Sub obj;
    cout << "Stop" << endl;

    return 0;
}