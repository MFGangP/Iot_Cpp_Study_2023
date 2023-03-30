#include <iostream>
using namespace std;

class Point
{
    int xpos, ypos;
public:
    Point(int x = 0 , int y = 0)
    :xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", "<< ypos <<  ']' << endl;
    }
    // 연산자 오버로딩 할 때나 friend를 써서 외부에서 접근 가능하게 해주는거고
    // 은닉성을 해치니까 다른데는 쓰면 안된다.
    friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}

int main()
{
    Point pos1(3, 4);
    Point pos2(10,20);
    Point pos3 = pos1 + pos2;
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return 0;
}