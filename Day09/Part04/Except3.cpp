#include <iostream>
using namespace std;

void divide(int a, int b)
{
    int c, d;
    try{
        if(b == 0) throw b; // 예외가 발생되면 b를 던져줘라
    
        c = a / b;
        cout << "몫 : " << c << endl;
        d = a % b;
        cout << "나머지 : " << d << endl;
        cout << "----------------------------------\n" << endl;
    }
    catch(int ex){
        cout << ex << "로 나눌 수 없습니다." << endl;
        cout << "예외가 발생을 해도 정상 종료!" << endl;
    }

}

int main()
{
    divide(100, 5);
    divide(15, 3);
    divide(10, 0);
    divide(100, 20);
    return 0;
}