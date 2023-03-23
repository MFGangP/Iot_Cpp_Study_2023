#include <iostream>
using namespace std;
/*
클래스 생성할 때 첫 글자는 대문자로 하는게 국룰
*/
//접근 제한 지시자
class Myclass{
    // 외부의 접근을 불허한다. (95%)
private:
    int private_val;
    // 외부 접근 가능
public:
    int public_val;
    // 상속에서만 접근 가능
protected:
    int protected_val;
public: // 멤버 함수 밖에서 쓰려면 public 무조건 써줘야된다.
    // 멤버 변수 값 바꾸는 법
    void set(int an)
    {
        private_val = an;
    }
    void get()
    {
        cout << "public_val : "<< public_val << endl;
        cout << "private_val : "<< private_val << endl;
    }
};

int main()
{
    Myclass o; // 객체 생성
    // o.private_val; // o.접근자
    o.public_val = 100;
    // o.protected_val;
    o.set(200);
    o.get();

    return 0;
}