#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    // 외부에서 함부로 건들면 안되니까 속성 자체는 접근을 막아버리고
    private:
        char name[30];
        int age;
    // 공개된 루트를 통해서 초기화를 시킬 수 있게 해준다
    public:
        // 생성자
        // 매개변수 원형 부분에는 이름 빠져도 된다. 정의 부분에는 빠지면 안됌
        Person(const char *aname, int aage) : age(aage) {
            // 뒤에 있는 문자열을 앞에 있는 문자열에 복사
            strcpy(name, aname);
        };

        void getData()
        {
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
        };
};
// 상속을 하게되면 부모클래스가 가지고 있는 속성을 그대로 물려받는거다.
// 접근 제한 지시자가 정해준 상태 그대로.
class Student : public Person
{
    private:
        int studentID;
    
    public:
        // 원칙적으로 얘를 만들려면 부모클래스 속성까지 다 넣어줘야하니까 3개가 들어가야한다.
        Student(const char* aname, int aage, int astudentID) : Person(aname, aage), studentID(astudentID) 
        { };
        // 함수 오버로딩 - 상속관계가 아닌 상태에서 함수 이름이 같은데 인자 갯수가 다른거.
        // 부모 자식 관계에서도 가능한데 상속관계의 부모 자식 사이는 함수 오버라이딩이라고 한다.
        // 상속에서 오버라이딩은 재정의, 오버로딩은 다중정의
        // 둘은 다른거다
        void showData(){
            // 부모 클래스 함수 가져와서 이름이랑 나이 표시
            getData();
            // 아이디 표시
            cout << "studentID : " << studentID << endl;
        };
};
// Person이라는 특성을 가지고 있으면서 학번, ID를 가지고 있으면 학생, 직장인이다 라는걸 나타낼 수 있음.
// 상속을 통해서 & 가 계속해서 이어지는 것.
// 자식 클래스로 내려올수록 많은 특징을 요구함.

int main()
{
    // 부모 클래스 생성자 생성
    Person ps("홍길동", 27);
    // 자식 클래스 생성자 생성
    Student st("홍길순", 27, 1);
    // Person의 표시 함수
    cout << "------------------" << endl;
    cout << "부모클래스 표시" << endl;
    cout << "------------------" << endl;
    ps.getData();
    // Person의 표시 함수
    cout << "------------------" << endl;
    cout << "부모 함수 가져와서 자식 클래스 표시" << endl;
    cout << "------------------" << endl;
    st.getData();
    // Student의 표시 함수
    cout << "------------------" << endl;
    cout << "자식클래스 표시" << endl;
    cout << "------------------" << endl;
    st.showData();
    return 0;
}