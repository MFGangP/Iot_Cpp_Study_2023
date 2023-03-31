#include <iostream>
using namespace std;

template <typename T>           // 클래스 템플릿 일반화
class CTest 
{
    private:
        T data;
    public:
        CTest(T adata) : data(adata) {}
        T getData()
        {
            return data;
        }
};
/*
template <>                     // 클래스 템플릿 특수화     
class CTest<char>
{
    private:
        const char data;
    public:
        CTest(const char adata) : data(adata){}
        char getData()
        {
            return data;
        }
};
*/
int main()
{
    CTest<int> d(170);
    cout << d.getData() << endl;
    // CTest<char*> c("안녕하세요");
    // cout << c.getData() << endl;

    return 0;
}