#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    // name의 값
    char *name;
    int age;
public:
    Person(char * myname, int myage)
    {
        // NULL 값 대비해서 1칸 늘리기
        int len = strlen(myname) + 1;
        // 동적 할당
        name = new char[len];
        // 선언 이후에 넣는거니까 strcpy
        strcpy(name, myname);
        age=myage;
    }    
    Person() // 초기화
    {
        name = NULL;
        age = 0;
        cout << "called Peson()"<<endl;
    }
    // 생성자
    void SetPersonInfo(char * myname, int myage)
    {
        name = myname;
        age = myage;
    }
    // 보여주기
    void ShowPersonInfo() const
    {
        cout << "이름 : " << name << ", ";
        cout << "나이 : " << age << endl;
    }
    // 소멸자
    ~ Person(){
        delete [] name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    // 객체 배열 Person 타입의 parr 객체 주소 값 저장 가능한 배열칸 3개 생성
    Person * parr[3];
    // 이름칸 배열은 char타입 namestr 칸은 100개
    char namestr[100];
    int age;
    // 객체 배열에 for 문 돌면서 한개씩 집어넣어라
    for(int i=0; i<3; i++)
    {
        cout << "이름 : ";
        cin >> namestr;
        cout << "나이 : ";
        cin >> age;
        parr[i] = new Person(namestr, age); 
    }
    // 순서대로 출력
    parr[0] -> ShowPersonInfo();
    parr[1] -> ShowPersonInfo();
    parr[2] -> ShowPersonInfo();
    delete parr[0];
    delete parr[1];
    delete parr[2];
    return 0;
}