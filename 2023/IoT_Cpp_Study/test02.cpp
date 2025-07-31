#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char name[30];
    int birthday;

public:
    Person(const char* aname = "ȫ�浿", int abirthday = 19990909) : birthday(abirthday)
    {
        strcpy(name, aname);
    }

    void ShowPerson()
    {
        cout << "�̸� : " << name << endl;
        cout << "���� : " << birthday << endl;
    }

};

int main()
{
    Person* p1 = new Person("ȫ���");
    p1->ShowPerson();

    Person* p2 = p1;
    p2->ShowPerson();

    Person* p3(p2);
    p3->ShowPerson();

    delete p1;

    return 0;
}