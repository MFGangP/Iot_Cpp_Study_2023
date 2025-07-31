#include <iostream>
using namespace std;

class Person
{
private:
    char name[30];
    int birthday;

public:
    Person(const char* aname, int abirthday) :birthday(abirthday) 
    {
        strcpy(name, aname);
    }

    void ShowPerson()
    {
        cout << "이름 : " << name << endl;
        cout << "생일 : " << birthday << endl;
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

    return 0;
}