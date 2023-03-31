#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char name[30]; //스텍
        int birthday;

    public:
        Person(const char* aname, int abirthday) : birthday(abirthday) 
        {
            // 얕은 복사
            // 생성자는 멤버 대 멤버를 단순 복사
            strcpy(name, aname);
        }
        
        void ShowPerson()
        {
            cout << "이름 : " << name << endl;
            cout << "생일 : " << birthday << endl;
        }
        ~Person()
        {
            cout << "heap 영역 해제" << endl;
            // delete name;
        }
};

int main()
{
    Person p1("홍길동", 19990909);
    p1.ShowPerson();

    Person p2(p1);
    p2.ShowPerson();

    Person p3 = p2;
    p3.ShowPerson();
    
    Person p4("홍길순", 20001010);
    p4.ShowPerson();
    p4 = p1;
    p4.ShowPerson();
    
    return 0;
}