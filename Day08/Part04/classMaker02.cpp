#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char *name;
        int birthday;

    public:
        Person(const char* aname, int abirthday = 19990909) : birthday(abirthday) 
        {
            int len = strlen(aname) + 1;
            name = new char[len];
            strcpy(name, aname);
        }
        
        void ShowPerson()
        {
            cout << "이름 : " << name << endl;
            cout << "생일 : " << birthday << endl;
        }

        ~Person()
        {
            delete name;
        }
};

int main()
{
    Person* p1 = new Person("홍길순");
    p1->ShowPerson();

    Person* p2 = p1;
    p2->ShowPerson();

    Person* p3(p2);
    p3->ShowPerson();

    delete p1;
    
    return 0;
}