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
    char name[10];
protected:
    // ��� �Լ�(= �޼ҵ�) : ���
public:
    // ������ = ��� ������ �ʱ�ȭ ��Ű�� ���
    // a = �Ű����� ���ξ�
    // ���ͷ� = ���
    // ���ڿ� const ���ȭ ����� �ȴ�.
    void set(char aId, int aAge, const char* aName)
    {
        // SET �̶�� �Լ��� �Է°����� �ʱ�ȭ �ϴ°Ŵ�.
        id = aId;
        // �⺻ �ڷ����鸸 ���� �����ڰ� �����ϴ�.
        // ������ �����ε��� �ؾ� ����� �� �ִ�.
        // strcpy
        age = aAge;
        strcpy_s(name, 10, aName);
        // ���־� ��Ʃ��� strcpy(name, 10, aName);       
    };
    void get()
    {
        cout << "���̵� : " << id << endl;
        cout << "���� : " << age << endl;
        cout << "�̸� : " << name << endl;
    };
};

int main()
{
    MyClass Me;
    Me.set(1, 27, "Hyeon");
    Me.get();
    return 0;
}