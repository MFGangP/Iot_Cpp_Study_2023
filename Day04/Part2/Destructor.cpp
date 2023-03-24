#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char *name; // 이름을 배열 형태로 받을거니까 주소값으로 받는다.
        int age;
    public:
        // 생성자 이름이랑 나이 두가지를 받을껀데
        Person(char * myname, int myage)
        {
            // name이라는 변수에 모자라거나 넘칠 일을 방지하기위해 한칸 늘려서 대입
            int len = strlen(myname)+1;
            name = new char[len];
            // 문자열 복사
            strcpy(name, myname);
            age = myage;
        }
        void ShowPersonInfo() const
        {
            cout<<"이름 : "<<name<<endl;
            cout<<"나이 : "<<age<<endl;
        }
        ~Person()
        {
            delete []name;
            cout<<"calles destructor!"<<endl;
        }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Jang dong gun", 41);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}