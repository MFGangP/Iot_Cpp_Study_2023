#include <iostream>
using namespace std;

class Sosimple
{
    private:
        int num;
    public:
    Sosimple(int n) : num(n)
    {}
    Sosimple& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void ShowData() const
    {
        cout << "num : " << num << endl;
    }
};
int main(void)
{
    const Sosimple obj(7);
    // obj.AddNum(20);
    obj.ShowData();
    return 0;
}
