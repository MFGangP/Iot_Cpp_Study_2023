#include <iostream>
#include <cstring>
using namespace std;

// 현실 세계에 존재하는 사물을 표현한다 할 때
class Human
{   
// 멤버 변수 - 속성
// 외부에서 접근을 금지시킨다.
private: // 현재는 스텍 영역에 할당되어 있음
    // 배열을 선언 할 때 초기화는 가능하다.
    // 객체의 속성별로 할당받음.
    char *name; 
    // char name[20];
                                        // 객체 배열
    // Human ary[10]; 위에 애랑 똑같다. ary[] 방하나마다 Human 타입의 객체를 저장할 수 있다.
    // 타입  기본 자료형
    int id; // 스텍
    int age; // 스텍

public:
// 디폴트 생성자
    // 초기값을 설정하는 생성자를 만들어놔야된다.
    // *aname = aname[]
    Human(const char *aname, int aid, int aage) 
    {
        // 동적 할당 해줄껀데 데이터 타입 지정해주고 저장공간 크기 설정
        // 캐릭터 형태의 포인터에다가 크기 1 더한 값을 넣는다.
        // null 값 들어갈거 대비  
        name = new char[strlen(aname) + 1]; // 힙영역에 할당하는 방법 - 동적할당
        strcpy(name, aname); // 선언하고 난 다음 문자열을 넣을 때는 이렇게
        id = aid;
        age = aage;
    }
    // new 해서 동적할당 했으니까 없애줘야된다.
    // 소멸자 - 객체를 소멸시킨다.
    ~ Human()
    {
        // 배열 타입을 해체 할 때 이렇게
        delete [] name;
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
    Human h("홍길동", 1, 30);
    h.getData();

    // 클래스가 자료형이다.
    Human hary[3] = {Human("김영희", 2, 23), Human("김철수", 3, 24), Human("홍길순", 4, 20)};
    // 객체 배열
    hary[0].getData();
    hary[1].getData();
    hary[2].getData();
    return 0;
}