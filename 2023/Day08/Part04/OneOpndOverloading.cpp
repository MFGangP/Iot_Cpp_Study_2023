#include <iostream>
using namespace std;

class Point
{
    int xpos, ypos;
    
public:
    Point(int x=0, int y=0)
    :xpos(x), ypos(y){}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' <<endl;
    }
    // 참조형
    Point& operator++()
    {   
        // 객체에 있는 멤버 변수 + 1
        xpos += 1;
        ypos += 1;
        // 포인터 리턴
        return *this;
    }
    // 전역 함수로 선언되어있는 연산자 오버로딩을 클래스로 만들어놨음
    friend Point& operator--(Point &ref); // friend 전역함수
};
// 얘가 클래스에 접근해서 멤버 변수를 사용 할 수 있게 되어있다.
Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main()
{
    Point pos(1, 2);
    ++pos; // 1씩 증가
    pos.ShowPosition();
    --pos; // 1씩 감소
    pos.ShowPosition();
    
    ++(++pos); // 2씩 증가
    pos.ShowPosition();
    --(--pos); // 2씩 감소
    pos.ShowPosition();
    
    int num = 10;
    cout << num++ << endl;
    cout << ++num << endl;

    return 0;
}