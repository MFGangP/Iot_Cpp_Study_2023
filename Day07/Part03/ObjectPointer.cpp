#include <iostream>
using namespace std;

class Person
{
    public:
        void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
    public:
        void Study() { cout << "Study" << endl; }
};
// Person을 PartTimeStudent이 간접 상속 
class PartTimeStudent : public Student
{
    public:
        void Work() { cout << "Work" << endl; }
};

int main(void)
{
    // 포인터는 무조건 동일한 타입을 가리켜야된다. 포인터 타입이 중요함.
    // 자식 클래스는 속성이 많고, 부모 클래스는 속성이 적다.
    // 부모는 자식을 가리킬 수 있다.
    // 대신 접근 범위는 부모클래스가 가진 속성만으로 한정된다.
    // ptr은 전부다 객체
    Person * ptr1 = new Student();
    Person * ptr2 = new PartTimeStudent();
    Student * ptr3 = new PartTimeStudent();
    // Person 클래스에 있는 매서드이기 때문에 타입이 같다.
    // 접근이랑 가리키는거랑 다르다. ************************
    // 주소를 가지고 가리키는 객체에 접근할때는 객체 포인터를 통해 가능하다.
    ptr1->Sleep(); // 동일한 타입
    ptr2->Sleep(); 
    // 부모 클래스에 있는 타입을 가지고 자식 클래스에 접근 안된다.
    ptr3->Study();
    // 상속받은 모든 것에 접근 가능
    // 포인터 타입이 기준 - 상속받는 Person이나 Student에 접근가능
    PartTimeStudent * ptr = new PartTimeStudent();
    ptr->Sleep();
    ptr->Study();
    ptr->Work();

    delete ptr1;
    delete ptr2;
    delete ptr3; 
    return 0;
}