#include <iostream>
using namespace std;

void static_Counter()
{   // 지역변수로 선언했던 static의 특징
    // 얘는 초기값을 안줘도 자동으로 0으로 초기화 되어있다.
    static int cnt; // 프로그램 시작과 동시에 데이터 영역에 미리 할당
                    // 프로그램 끝날 때까지 유지
    cnt++;
    cout << "static Current cnt : " << cnt << endl;
};
void Counter()
{
    // 얘는 초기값이 필요한데
    int cnt = 0; // 실행 될 때마다 새로운 메모리를 할당 받아서 작동한다.
    cnt++;
    cout << "Current cnt : " << cnt << endl;
};
int main(void)
{
    for(int i=0; i<10; i++)
    {
        static_Counter(); 
        Counter();
    }
    return 0;
}
