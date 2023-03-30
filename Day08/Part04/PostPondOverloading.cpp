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
    // 객체 맴버 변수에다 1증가 시키기
    Point& operator++() // 전위증가
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    // 출력을 상수화 시킨거 - temp 상수화
    const Point operator++(int) // 후위증가 int(키워드)는 그냥 구분하려고 쓴거지 별 뜻 없다.
    {
        // 임시 객체를 하나 만들어서 초기화 시킨다음 던져주고 값을 증가시키기 위해 이렇게 쓴다.
        // 얘도 상수화 해줘야지.
        const Point temp(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return temp;
    }
    // 외부에서 함수 쓸 수 있게 friend 처리
    // 전역 함수로 선언되어있는 연산자 오버로딩을 클래스로 만들어놨음
    // 참조자 형태 
    friend Point& operator--(Point &ref);
    // 전역, 출력은 상수화
    friend const Point operator--(Point &ref, int); // 후위증가 int(키워드)는 그냥 구분하려고 쓴거지 별 뜻 없다.

};
// 클래스에 접근해서 멤버 변수를 사용 할 수 있게 되어있다.
Point& operator--(Point &ref) // 전위감소
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point &ref, int) // 후위감소
{
    const Point temp(ref);
    ref.xpos -=1;
    ref.ypos -=1;
    return temp;
}

int main()
{
    Point pos(3, 5);
    Point cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();
    
    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}