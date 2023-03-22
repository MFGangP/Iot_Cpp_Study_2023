#include <iostream>
using namespace std;

int main()
{
    int num1 = 1020;
    int &num2 = num1;   // 참조자가 선언부에 올거면 초기화를 바로 해줘야한다
                        // 아니면 오류뜬다.
    num2 = 3047;
    cout<<"VAL : "<<num1<<endl;
    cout<<"REF : "<<num2<<endl;

    cout<<"VAL : "<<&num1<<endl;
    cout<<"REF : "<<&num2<<endl;

    return 0;
}