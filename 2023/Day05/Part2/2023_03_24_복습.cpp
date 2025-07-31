#include <iostream>
#include <cstring>
using namespace std;

// 현실 세계에 존재하는 사물을 표현한다 할 때
class Human
{   
// 멤버 변수 - 속성
// 외부에서 접근을 금지시킨다.
// 객체의 속성별로 할당받음.
private: // 현재는 스텍 영역에 할당되어 있음
    // 배열을 선언 할 때 초기화는 가능하다.
    char name[20]; // 힙 으로 보낼예정
    int id; // 스텍
    int age; // 스텍

public:
// 디폴트 생성자
    // 초기값을 설정하는 생성자를 만들어놔야된다.
    Human(const char aname[20], int aid, int aage) 
    {
        strcpy(name, aname); // 선언하고 난 다음 문자열을 넣을 때는 이렇게
        id = aid;
        age = aage;
    }
// 멤버 함수 - 행동
    // a = argument 
    // void setData(const char aname[20], int aid, int aage)
    // {
    //     // 배열은 만들어놓고 대입하는 건 안된다.
    //     // name = "홍길동";
    //     strcpy(name, aname); // 선언하고 난 다음 문자열을 넣을 때는 이렇게
    //     id = aid;
    //     age = aage;
    // }
    void getData()
    {
        cout << "이름 : " << name << endl;
        cout << "학번 : " << id << endl;
        cout << "나이 : " << age << endl;
    }
    
};

int main()
{
    // Human h;
    // h.setData("홍길동", 1, 30);
    
    // 인수 3개를 동시에 던져주면서 생성
    Human h("홍길동", 2, 30);
    h.getData();

    return 0;
}