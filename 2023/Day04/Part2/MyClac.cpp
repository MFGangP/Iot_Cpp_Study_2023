#include <iostream>
using namespace std;

int input_num1;
int input_num2;
char input_sign;

class MyCalu {

private:
    int num1;
    int num2;
    char sign;

public:
// 생성자로 초기화한다.(콜론 초기화 == 초기화 리스트)
    MyCalu(int input_num1, char input_sign, int input_num2) 
    : num1(input_num1), sign(input_sign), num2(input_num2) {}

    float Elementary_arithmetic()
    {
        int tmp = 0;
        if (input_sign == '+')
        {
            tmp = num1 + num2;
            cout << num1 << " + " << num2 << " = " << tmp << endl;
        }
        else if (input_sign == '-')
        {
            tmp = num1 - num2;
            cout << num1 << " - " << num2 << " = " << tmp << endl;
        }
        else if (input_sign == 'x')
        {
            tmp = num1 * num2;
            cout << num1 << " x " << num2 << " = " << tmp << endl;
        }
        else if (input_sign == '%')
        {
            tmp = num1 / num2;
            cout << num1 << " % " << num2 << " = " << tmp << endl;
        }
        else
        {
            cout << "올바른 기호를 입력해주세요" << endl;
        }
    }
    // void add()
    // {
    //     int tmp = 0;
    //     tmp = num1 + num2;
    //     cout << num1 << "+" << num2 << "=" << tmp << endl;
    // }
    // void mul()
    // {
    //     int tmp = 0;
    //     tmp = num1 * num2;
    //     cout << num1 << "*" << num2 << "=" << tmp << endl;
    // }
    // void sub()
    // {
    //     int tmp = 0;
    //     tmp = num1 - num2;
    //     cout << num1 << "-" << num2 << "=" << tmp << endl;
    // }
    // void div()
    // {
    //     float tmp = 0;
    //     tmp = num1 / num2;
    //     cout << num1 << "%" << num2 << "=" << tmp << endl;
    // }
};
// 이렇게 밖으로 빼면 전역이기 때문에 어디 소속인지 알려줘야한다.
//    MyCalu::MyCalu(int input_num1, char input_sign, int input_num2) 
//    : num1(input_num1), sign(input_sign), num2(input_num2) {}

int main()
{
    cout << "첫번째 숫자를 입력해주세요 : ";
    cin >> input_num1;
    cout << "두번째 숫자를 입력해주세요 : ";
    cin >> input_num2;
    cout << "실행 할 연산 기호를 입력해주세요 (+,-,x,%) : ";
    cin >> input_sign;

    MyCalu calc(input_num1, input_sign, input_num2);
    calc.Elementary_arithmetic();
}