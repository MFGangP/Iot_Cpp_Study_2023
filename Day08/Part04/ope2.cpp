// 연산자 오버로딩
#include <iostream>
using namespace std;

class Myclass
{
    private:
        int value;
    
    public:
        Myclass(int avalue) : value(avalue) { }
        // operator+ 이거 자체가 이름이다.
        // 객체를 매개변수에 집어넣을 때는 참조 형태로 써야한다.
        // 객체 형태로 쓰면 무한반복
        Myclass operator+(const Myclass & other) const
        {
            return Myclass(value + other.value);
        }
        void print()
        {
            cout << "value : " << value << endl; 
        }

};

int main()
{
    Myclass mc(10);
    mc.print();

    Myclass cmc(mc);
    cmc.print();

    Myclass ccmc(cmc);
    ccmc.print();
    // +는 객체 덧셈은 지원하지 않는다.
    // 객체를 더할 수 있게끔 오버로딩 하면 사용할 수 있다. 연산자 오버로딩
    Myclass amc = mc + cmc + ccmc;
    amc.print();
    return 0;
}