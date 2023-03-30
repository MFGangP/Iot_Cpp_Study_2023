#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0) : xpos(x), ypos(y)
        {

        }
        void ShowPosition() const
        {
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
        Point operator*(int times)
        {
            Point pos(xpos * times, ypos * times);
            return pos;
        }
        friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)
{
    // 멤버 함수로는 안되고 전역 함수로
    // 들어온 값 위치만 서로 바꿔주고 리턴 시키면 된다.
	return ref * times;
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	return 0;
}