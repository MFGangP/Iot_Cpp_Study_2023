#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
 
class Person{
private:
    int age;        // 나이
    char name[50];  // 이름
public:
    Person(int myage, const char * myname) : age(myage)
    {
        strcpy(name, myname);
    }
    // 변경 없이 출력만
    void WhatsYourName() const
    {
        cout << "My name is " << name << endl;
    }
    // 변경 없이 출력만
    void HowOldAreYou() const
    {
        cout << "I'm " << age << " years old" << endl;
    }
};
// 상속의 문법
// [클래스 키워드, 클래스 이름]은 
// [public(접근 제한 지시자), 클래스 이름]을 상속받는다
// 자식(파생 클래스, 서브 클래스) : 부모 클래스(슈퍼 클래스, 기초 클래스, 베이스 클래스)
class UnivStudent : public Person{      // Person 클래스 상속
private:
    char major[50];     // 전공 과목
    // 순수하게 자기 멤버 변수는 한개밖에 없는데
    // 생성자는 변수를 여러개 받는다
public:
    // 서브 클래스의 생성자 중요하다. *************************** 젤 중요
    // 부모가 가지고 있는 모든걸 다 물려받는다. 초기값에 활용해야 됌
    UnivStudent(const char * myname, int myage, const char * mymajor) : Person(myage, myname) 
    // 앞에서 받은 두 개의 변수를 콜론 초기화로 초기화 하는데,
    // 부모 클래스의 생성자를 호출해서 초기화
    {
        strcpy(major, mymajor);
    }
    void WhoAreYou() const
    {
        WhatsYourName();
        HowOldAreYou();
        cout<<"My major is " << major << endl << endl;
    }
};
 
int main(void){
    // 첫번째 객체
    UnivStudent ustd1("Lee", 22, "Computer end.");
    // 앞에 두놈은 상속받은 슈퍼클래스의 매개 변수 
    // 상속 받았기 때문에 넣어줘야한다.
    // 초기화는 부모클래스를 찾아가서 생성자를 불러와 초기화
    ustd1.WhoAreYou();
    // 두번째 객체
    UnivStudent ustd2("Yoon", 21, "Electronic eng.");
    ustd2.WhoAreYou();
    return 0;
}