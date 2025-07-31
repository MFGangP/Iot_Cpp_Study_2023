#include <iostream>
using namespace std;

int input_num1;
int input_num2;

class MyCalu {

private:
    int num1;
    int num2;

public:

    MyCalu(int input_num1, int input_num2) : num1(input_num1), num2(input_num2){}

    void add()
    {
        int tmp = 0;
        tmp = num1 + num2;
        cout << num1 << "+" << num2 << "=" << tmp << endl;
    }
    void mul()
    {
        int tmp = 0;
        tmp = num1 * num2;
        cout << num1 << "*" << num2 << "=" << tmp << endl;
    }
    void sub()
    {
        int tmp = 0;
        tmp = num1 - num2;
        cout << num1 << "-" << num2 << "=" << tmp << endl;
    }
    void div()
    {
        float tmp = 0;
        tmp = num1 / num2;
        cout << num1 << "%" << num2 << "=" << tmp << endl;
    }

};

int main()
{
    cout << "첫번째 숫자를 입력해주세요 : ";
    cin >> input_num1;
    cout << "두번째 숫자를 입력해주세요 : ";
    cin >> input_num2;

    MyCalu calc(input_num1, input_num2);
    calc.add();
    calc.mul();
    calc.sub();
    calc.div();
}