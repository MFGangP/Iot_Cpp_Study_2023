#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout<<"객체생성"<<endl;
    }
    SoSimple& Adder(int n)
    {
        num += n;
        return * this;
    }
    SoSimple& ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
};

int main()
{
    SoSimple obj(3);
    SoSimple &ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;
}