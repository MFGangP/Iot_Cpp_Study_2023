#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) { }

        void ShowPosition() const
        {
            cout << '['<< xpos << ", " << ypos << ']' << endl;
        }
        Point operator+(const Point &ref)
        {
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    // 멤버함수 , 전역함수 표현 차이가 난다.
    // 이건 멤버 함수로써 오버로딩 시킬때 나타나는 형태.
    // 피연산자, 이항연산자, 나중에 가면 단항연산자도 나옴.
    Point pos3 = pos1.operator+(pos2);
    // 컴파일 하면 이 형태로 바껴서 계산된다.
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    
    return 0;
}