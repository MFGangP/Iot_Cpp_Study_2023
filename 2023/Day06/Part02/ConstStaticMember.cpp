#include <iostream>
using namespace std;

class CountryArea
{
    public:
        // const 는 선언과 동시에 초기화 해야하고
        // static은 클래스 밖에서 초기화 해야하는데
        // 두개 같이 붙어있으면 이런 형태로 가능하다.
        const static int RUSSIA = 1707540;
        const static int CANADA = 998467;
        const static int CHINA = 957290;
        const static int SOUTH_KOREA = 9922;
};

int main(void)
{
    cout << "러시아 면적 : "<< CountryArea::RUSSIA<<"㎢"<<endl;
    cout << "캐나다 면적 : "<< CountryArea::CANADA<<"㎢"<<endl;
    cout << "중국 면적 : "<< CountryArea::CHINA<<"㎢"<<endl;
    cout << "한국 면적 : "<< CountryArea::SOUTH_KOREA<<"㎢"<<endl;
    return 0;
}
