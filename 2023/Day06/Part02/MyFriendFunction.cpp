#include <iostream>
#include <cstring>
using namespace std;

class Point; // 위에서 아래로 훑기 때문에 미리 있다는걸 선언 해놓는 것
// 밑에가면 포인트라는 클래스가 있을 거야.
class PointOP
{
    private:
        int opcnt;
    public:
        PointOP() : opcnt(0) {}
        // Point 타입을 반환하고 있다. 
        Point PointAdd(const Point&, const Point&);
        Point PointSub(const Point&, const Point&);

    ~PointOP()
    {
        cout << "Operation times : " << opcnt << endl;
    }
};
class Point
{
    private:
        int x;
        int y;
    public:
        Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
        {}
        // 원형에다 선언
        // PointOP에서 Point에 접근해 x, y를 꺼내 쓸 수 있다.
        friend Point PointOP :: PointAdd(const Point&, const Point&);
        friend Point PointOP :: PointSub(const Point&, const Point&);
        friend void ShowPointPos(const Point&);
};
Point PointOP:: PointAdd(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    // 매개변수 두개를 더하고 리턴  
    return Point(pnt1.x+pnt2.x, pnt1.y+pnt2.y);
}

Point PointOP:: PointSub(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x-pnt2.x, pnt1.y-pnt2.y);
}

int main(void)
{
    // pos 라는 객체 생성
    Point pos1(1, 2);
    Point pos2(2, 4);
    // PointOP 타입의 op 선언
    PointOP op;
    // op객체의 함수를 호출하면서 객체 전달
    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos2, pos1));
    return 0;
}
// 전역 함수 클래스에 속해있는 매서드 아님
void ShowPointPos(const Point& pos)
{
    cout << "x : " << pos.x << ", ";
    cout << "y : " << pos.y << endl;
}
