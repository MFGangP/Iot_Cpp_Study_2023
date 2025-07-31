#include <iostream> 

namespace mystd
{
    using namespace std;
    class ostream
    {
    public:
        // ������ �ֵ� ���� ������ �����ε� �ؾߵȴ�.
        // ���ڰ� �׳� �ڱ⸸�� ���� �����̽��� ���� ���°��� �׷��� �ۼ� ����
        // Ŭ���� �̸� :: �Լ� �̸� (�Է� ��)
        void operator<<(const char* str) // ���ڿ� ���� �ּ�
        {
            // ���
            printf("%s", str);
        }
        // << ��� ������
        void operator<<(char str)
        {
            printf("%c", str);
        }

        void operator<<(int num)
        {
            printf("%d", num);
        }

        void operator<<(double e)
        {
            printf("%g", e);
        }

        // ostream& endl(ostream& ostm) �Լ��� ���ڷ� ���޹���
        // �Լ������� - �Լ��� �����ʹ�.
        // �Լ��� �Ӹ��κ��̶� ����� �Ȱ��ƾ��Ѵ�.
        // (*fp)�� �Լ��� �Ӹ� �κ�
        // ostream& (*fp)(ostream& ostm)
        void operator<<(ostream& (*fp)(ostream& ostm))
        {
            fp(*this);
        }
    };
    // endl �Լ�
    // ����Ǹ� �Լ��� �ڵ� ���׸�Ʈ�� ������ �ȴ�. 
    // �Լ� �ּҸ� ���� ã�ư��°� �װ� �Լ� �����ʹ�.
    // endl�� �Լ� �Ӹ� �κ�
    ostream& endl(ostream& ostm)
    {
        ostm << '\n'; // ��ü�� �ڱ��ڽ� ���๮�� ���� - ���� ���Ѷ�
        fflush(stdout); // stdout�� ��� ���� - ���� ����
        // ���� �ȿ� �ԷµǾ��ִ� ���� �� ��������ϱ� ������(���� �� �Է��� ���� �����ϴ��� �˷��ִ� ��)�� �� ������ ����.
        // ���� �����͸� 0������ �Է� �����ϰ� ������ִ� ��
        // �츮�� ġ�� Ű���� �Է°��� �Է� ���ۿ� ���� �ȴ�.
        // �Է� ���ۿ� �ִ� ���� �����ͼ� �о�°� cin 
        return ostm;
        // ��µ� ��� ���ۿ� ����ȴ�, ��¿� ���õ��ִ� �ڵ带 ������(ȣ��) �ܼ�â�� ��µǴ� ��.
    }

    ostream cout; // ���ο� ostream Ŭ������ �ִ� ��ü�� �̸� 
    // ��ü ������ �پ��� �⺻�ڷ��� �����͸� ������� << ������ �����ε��� �ϰ� �ִ�.
};

int main(void)
{
    // using ���ӽ����̽��̸�::��� ��
    // ���ӽ����̽� �̸� ���̵� ����ϰ� ����
    // ������ using ����
    using mystd::cout;
    using mystd::endl;

    cout << "Simple String"; // ���� ������ ������ ���ڿ��� ������ �ȴ�. ù ������ ���� �ּҸ� �����ͷ� ã�ư�. 
    cout << endl;
    cout << 3.14;
    cout << endl;
    cout << 123;
    endl(cout);

    return 0;
}