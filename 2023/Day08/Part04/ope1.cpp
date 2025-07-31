#include <iostream>
using namespace std;

class Myclass
{
    private:
        int n1;
        int n2;
        char* name;

    public:
    // 디폴트 초기화 and 콜론 초기화
        Myclass(int an1 = 0, int an2 = 0, char* aname = nullptr) : n1(an1), n2(an2), name(aname) { }
        void ShowData()
        {
            cout << n1 << ", " << n2 << ", " << name << endl;
        }
};

int main()
{
    Myclass mc(1, 27, "홍길동");
    mc.ShowData();
    Myclass cmc(mc); // cmc = mc
    cmc.ShowData();
    // 인자 없는 객체 - 디폴트 초기화
    Myclass mc1;
    mc1 = mc;
    mc1.ShowData();

    return 0;
}