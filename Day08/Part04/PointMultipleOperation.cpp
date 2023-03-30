#include <iostream>
using namespace std;

class Point
{
    int xpos, ypos;

    public:
        // 생성자로 초기화
        Point(int x=0, int y=0)
        :xpos(x), ypos(y) {}

    void ShowPosition() const
    {
        cout << '[' << xpos << ", "<< ypos << ']' <<endl;
    }

    Point operator*(int times)
    {
        // 임시 객체를 하나 만들어서 초기화 시킨다음 던져주려고 pos 만듦
        Point pos(xpos*times, ypos*times);
        return pos;
    }
};

Point operator*(int times, Point& ref)
{
    return ref*times;
    
}

int main()
{
    Point pos(1, 2);
    Point cpy;
    // 앞에서 곱하든 뒤에서 곱하든 교환법칙 때문에 상관없음
    cpy = 3*pos;
    cpy.ShowPosition();
    
    cpy = 3*pos*2;
    cpy.ShowPosition();
    return 0;
}