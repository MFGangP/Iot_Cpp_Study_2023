#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int n) : num(n)
    { }
    SoSimple(const SoSimple & copy) : num(copy.num)
    {
        cout<<"called SoSimple(const SoSimple &copy)" << endl;
    }
    void ShowData()
    {
        cout << num << endl;
    }
};
void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
};
int main()
{
    SoSimple obj(7);
    cout << "함수호출 전" << endl;
    SimpleFuncObj(obj);  // SoSimple sim2(sim1); 으로 변환.
    cout << "함수호출 후" << endl;
    return 0;
}