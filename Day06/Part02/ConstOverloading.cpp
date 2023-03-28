#include <iostream>
using namespace std;

class Sosimple
{
    private:
        int num;
        int num1;
        const int n = 10;
    public:

    Sosimple(int n) : num(n) // n(n1){} 되드라
    {}
    Sosimple& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void SimpleFunc()
    {
        cout << "SimpleFunc : " << num << endl;
    }
    void SimpleFunc() const
    {
        cout << "const SimpleFunc : " << num << endl;
    }
};

void YourFunc(const Sosimple &obj)
{
    obj.SimpleFunc();
}
int main(void)
{
    Sosimple obj1(2);
    const Sosimple obj2(7);
    
    obj1.SimpleFunc();
    obj2.SimpleFunc();

    YourFunc(obj1);
    YourFunc(obj2);

    return 0;
}
