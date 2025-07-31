#include <iostream>
using namespace std;
// 자료형 타입을 달리 쓰고싶을 때 쓰는게 템플릿.
// 자료형 갯수가 같아야한다.
// 다형성 + 재활용 측면
template <typename T>
class Point{

private:
    T xpos, ypos;
public:
    Point(T x = 0 , T y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const{
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};
 
int main(void){
    Point<int> pos1(3, 4);
    pos1.ShowPosition();
 
    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();
 
    Point<char> pos3('P', 'F'); // 좌표정보를 문자로 표시하는 상황의 표현
    pos3.ShowPosition();

    return 0;
}
