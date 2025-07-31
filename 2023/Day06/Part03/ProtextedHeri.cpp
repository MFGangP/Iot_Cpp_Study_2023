#include <iostream>
using namespace std;

class Base
{
    private:
        int num1;
    protected:
        int num2;
    public:
        int num3;

        Base() : num1(1), num2(2), num3(3)
        {  }
};

class Derived : public Base { }; // empty

int main()
{
    Derived drv;
    // Protected를 접근 제어 지시자로 쓰면 컴파일 에러 발생
    cout << drv.num3 << endl;  
    return 0;
}