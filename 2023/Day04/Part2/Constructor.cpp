#include <iostream>
using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;
public:
    //  생성자 오버로딩
    SimpleClass()
    {
        printf("default 생성자\n");
        num1=0;
        num2=0;
    }
    SimpleClass(int n)
    {
        printf("인수 하나 갖는 생성자\n");
        num1=n;
        num2=0;
    }
    // 이렇게 하면 값이 안들어왔을 때 default 값으로 0이 나간다.
    // 하지만 디폴트 값을 따로 주고싶으면 별도로 만들어줘야한다.
    // SimpleClass(int n1 = 0, int n2 = 0) 
    SimpleClass(int n1, int n2)
    {
        printf("인수 두개 갖는 생성자\n");
        num1=n1;
        num2=n2;
    }
    /*
    SimpleClass(int n1, int n2)
    {
        num1=n1;
        num2=n2;
    }
    */
   void ShowData() const
   {
    cout << num1 << ' ' << num2 << endl;
   }
};

int main(void)
{
    SimpleClass sc1;
    sc1.ShowData();

    SimpleClass sc2(100);
    // SimpleClass sc2 = SimpleClass(100); 이거도 가능하다.
    // SimpleClass sc2(); 이거는 때려 죽여도 안된다 함수의 원형이라서
    sc2.ShowData();    

    SimpleClass sc3(100, 200);
    sc3.ShowData();
    return 0;
}