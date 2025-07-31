#include <iostream>
using namespace std;

class Ctest
{
    private:
        int num;
    public:
        Ctest(int n)
        {
            num = n;
            cout << num << endl;
            cout << "Ctest Constructor" << endl;
        }
        ~Ctest()    // 슈퍼클래스 소멸자
        {
            cout << "Ctest Destructor" << endl;
        }
};

class CtestSub : public Ctest
{
    private:
        int subn;
    public:
        CtestSub(int s, int n) : Ctest(s)
        {
            subn = n;
            cout << subn << endl;
            cout <<"CtestSub Constructor" << endl;
        }
        ~CtestSub() // 서브클래스 소멸자
        {
            cout << "CtestSub Destructor" << endl;
        }
};

int main()
{
    // 인자 있는 형식으로 만들었는데 인자 안주면 에러
    Ctest ct(10);
    cout << "------------------------------------" << endl;\
    CtestSub cs(20, 30);
    // 소멸자는 자식클래스가 먼저 실행
    return 0;
}