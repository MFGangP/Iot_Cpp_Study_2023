#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Ŭ���� ��� ������ ������ �� �ִ� ����� 3������ ǥ���ȴ�. (����)
class MyClass {
    // ������� : �Ӽ�
private: // �ܺο��� ���� �Ұ�, ���� �ٲٷ��� ��� �Լ��� �ٲٴ� �Ÿ� ����
    char id;
    // char id = 10; �̷��� �ȵȴ�.
    // �Ӽ� ���� �̷��� �ʱ�ȭ �ϴ°� �ǹ̰� ����.
    // ��ü�� ���� �� ������ �� �޶�ߵȴ�.
    // ���� ������ �Ἥ �׳� �־��
    int age;
    char *name;
public:
    // ������ = ��� ������ �ʱ�ȭ ��Ű�� ���
    // MyClass(char aId) : id(aId) {}
    // MyClass(char aId, int aAge) : id(aId), age(aAge) {}
    // MyClass(char aId, int aAge, const char *aName) : id(aId), age(aAge){
    //          };
    // �����ڰ� ȣ�� �� �� �ٷ� �ʱ�ȭ �ϴ� ���
    MyClass(char aId, int aAge, const char* aName) : id(aId), age(aAge)
    {
        int len = strlen(aName) + 1;
        name = new char[len];
        strcpy(name, aName);
    }
    // ������ ȣ��ǰ� ���� ���� �� �� �ʱ�ȭ �ȴ�.

    // a = �Ű����� ���ξ�
    // ���ͷ� = ���
    // ���ڿ� const ���ȭ ����� �ȴ�.
    // ���־� ��Ʃ��� strcpy(name, 10, aName);      
    void get()
    {
        if (age == 0 and name == 0)
        {
            cout << "���̵� : " << id << endl;
        }
        else if (name == 0)
        {
            cout << "���̵� : " << id << endl;
            cout << "���� : " << age << endl;
        }
        else
        {
            cout << "���̵� : " << id << endl;
            cout << "���� : " << age << endl;
            cout << "�̸� : " << name << endl;
        }
    }
    /*
    MyClass(char aId, int aAge, const char *aName); ������ ����

    MyClass::MyClass(char aId, int aAge, const char *aName){
        id = aId;
        age = aAge;
        strcpy(name, aName);
    } ������ ����
    */
    ~MyClass()
    {
        delete []name; // Ŭ���� �ȿ��� �̸� �ִ´ٰ� �� �迭 ����
        cout << "call destructor!" << endl;
    }
};

int main()
{

    MyClass Me('1', 27, "Hyeon");
    Me.get();

    return 0;
}