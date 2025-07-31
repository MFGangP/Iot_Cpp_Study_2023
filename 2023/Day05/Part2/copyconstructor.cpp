#include <iostream>
using namespace std;

class Myclass
{
private: // 매개변수 한개
    int num;
    
public:
    Myclass(int n1) : num(n1)
    {
        cout << "생성자 호출" << endl;
    }
    // 디폴트 생성자가 이렇게 생긴거다.
    // 객체 타입으로 적으면 그냥 끝나는거다.
    // const를 붙여서 원본이 바뀌는 일이 아예 없도록 만드는게 좋은 코드
    // explicit Myclass(const Myclass &copy) 묵시적 변환 방지 C 방식의 복사 방지
    // 대입을 막는다.
    Myclass(const Myclass &copy) // Myclass(Myclass copy) 이러면 무한루프 가는거야
    {
        cout << "복사생성자 호출" << endl;
        num = copy.num;
        // 참조하고 있는 객체의 num을 지금 생성하고자 하는 객체 num에다가 넣어라
    }
    // 매개변수 하나를 가진 객체
    void getData()
    {
        cout << num << endl;
    }
};

int main() // 객체를 복사할 때 쓰는 생성자
{
    // 디폴트 복사생성자가 안만들어도 자동으로 만들어진다.
    // 객체별로 맴버 변수는 스텍영역에 개별로 할당된다.
    // 복사 생성자의 매개 변수는 참조자 형태(참조형)
    // 문제는 배열같이 메모리를 할당받는 형태가 오면 해제할 때 문제가 생긴다.
    // 객체 형태로 부르면 무한루프에 빠진다.
    // 복사 생성자로 복사하면 얕은 복사
    // 힙 영역에 할당되있는 주소값을 포인터에 복사해서 사용하는거다.
    // 해제할 때 문제가 되는 이유 : 0001 -> 0001 복사
    // 해제 되어있는 값의 주소값을 복사한 놈이 가지고있다가 붕뜸.
    // 이게 얕은 복사
    // 깊은 복사는 할당받은 영역 자체를 복사해서 새로 생성 0001 -> 0002
    // 기존 객체가 사라지더라도 내가 할당 받은 주소는 계속해서 살아있음.
    Myclass m1(10);     // m2 를 만들껀데 초기 값을 m1으로 해라.
    Myclass m2 = m1;    // 복사생성자 호출. int num2 = num1; C 타입
    Myclass m3(m2);     // 복사생성자 호출 m3를 만드는데 m2를 초기값으로 생성해라
    m1.getData();
    m2.getData();
    m3.getData();
    return 0;
}