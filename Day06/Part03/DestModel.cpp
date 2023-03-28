#include <iostream>
#include <cstring>
using namespace std;
 
class Person{
private:
    char * name;
public:
    // 생성자
    Person(char * myname){
        // 문자열 받는데 NULL 값 들어가야 하니까 1 더 늘려줌
        name = new char[strlen(myname) + 1];
        // 복사할 때는 strcpy 써라
        strcpy(name, myname);
    }
    // 소멸자
    ~Person(){
        delete []name;
    }
    void WhatYourName() const{
        // 부모 클래스가 실행 됐다는거 보여주기위해 만듦
        cout << "My name is " << name << endl;
    }
};
/*UnivStudent 클래스는 접근 제한 지시자 public형의 부모 클래스 Person을 상속한다.*/
class UnivStudent : public Person{
private:
    char * major;
public:
    // 생성자
    // 부모클래스에서 이름을 받아오는데 초기화는 Person 생성자로 실행한다.
    // 왜냐 못건드니까
    UnivStudent(char * myname, char * mymajor) : Person(myname){
        // 건드릴 수 있으면 여기서 초기화를 하겠지
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    // 소멸자
    ~UnivStudent(){
        delete []major;
    }
    // 부모클래스 먼저 보여주고 자식 클래스 보여줌.
    void WhoAreYou() const{
        WhatYourName();
        // 자식 클래스가 나중에 실행된다는거 보여주려고 만듦
        cout << "My major is " << major << endl << endl;
    }
};
 
int main(void){
    // st1 객체 생성
    // 첫번째 값 = 부모 클래스 
    // 두번째 값 = 자식 클래스
    UnivStudent st1("Kim", "Mathmatics");
    st1.WhoAreYou();
    // st2 객체 생성
    // 첫번째 값 = 부모 클래스
    // 두번째 값 = 자식 클래스
    UnivStudent st2("Hong", "Physics");
    st2.WhoAreYou();
    return 0;
    /*
    st2 메모리 해제
    - 자식 해제
    - 부모 해제
    st1 메모리 해제
    - 자식 해제
    - 부모 해제
    데이터 영역 아니면 스텍 메모리의 특징을 가지고 있다. LIFO 후입선출
    */
}
