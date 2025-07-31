#include <iostream>
using namespace std;

class SoSimple
{
    private:
        int num;
    public:
    SoSimple(int n) : num(n)
    {
        cout << "create obj : " << num << endl;
    }
    ~SoSimple()
    {
        cout << "destroy obj : " << num << endl;
    }
    void ShowTempInfo()
    {
        cout << "My num is " << num << endl;
    }
};

int main()
{
    // [타입 + 이름]이 기본 베이스
    SoSimple(100); // 얘는 임시 객체 이런 형태 변수 선언은 없음. 이름이 없다.
    cout << "********** after make!" << endl << endl;
    SoSimple(200).ShowTempInfo();
    cout << "********** after make!" << endl << endl;
    const SoSimple &ref = SoSimple(300);
    cout << "********** after make!" << endl << endl;
    return 0;
}