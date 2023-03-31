#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char *name;
        int birthday;

    public:
        // 생성자, 디폴트 초기화, 콜론 초기화
        Person(const char* aname, int abirthday = 19990909) : birthday(abirthday) 
        {
            // 입력 받은 값 + NULL 값
            int len = strlen(aname) + 1;
            // 힙 - 동적할당
            name = new char[len]; // 얘가 있으니까 복사생성자 만드는것
            strcpy(name, aname); // 얕은 복사로도 복사는 되니까
        }

        void ShowPerson()
        {
            cout << "이름 : " << name << endl;
            cout << "생일 : " << birthday << endl;
            cout << "이름 주소 값 : %p" << &name << " - 생일 주소 값 : %p" << &birthday << endl;
        }

        // 깊은 복사
        // 값으로 같은 클래스 형태의 값을 받는데
        // 포인터로 참조하는 대상까지 깊게 복사
        Person(const Person& ref) : birthday(ref.birthday)
        {
            name = new char[strlen(ref.name) + 1]; // 힙
            strcpy(name, ref.name); 
        }

        ~Person()
        {
            cout << "heap 영역 해제" << endl;
            delete name;
        }
};

int main()
{
    // 이름만 동적 할당.
    // 내가 원래 한건 객체를 동적 할당했다. 
    Person p1("홍길동", 19990909);
    p1.ShowPerson();

    Person p2(p1);
    p2.ShowPerson();

    Person p3 = p2;
    p3.ShowPerson();
    
    Person p4("강감찬");
    p4.ShowPerson();
    
    p4 = p1;
    p4.ShowPerson();
}