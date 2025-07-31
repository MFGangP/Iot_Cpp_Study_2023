#include <iostream>
#include <cstring>
using namespace std;
// 최상위 부모 클래스
class Employee
{
    // 자원적인 측면에서 빈자리가 많으니 낭비
    char name[100];
public:
    // 생성자
    Employee(const char *name) // 문자열
    {
        // Employee의 name에 복사해서 넣어라
        strcpy(this->name, name);
    }
    // 그냥 매서드드
    void ShowYourName() const // 데이터 변경이 필요 없으니까 const로 미리 차단
    {
        cout << "name: "<< name << endl;
    }
};
// public 접근 제어 지시자로 Employee 부모 클래스를 상속받은 PermanentWorker 자식 클래스
class PermanentWorker : public Employee
{
    int Salary;
public:
    // 생성자 특) 출력 없음
    // name은 프라이빗에 들어있는 속성이니까 부모의 생성자를 호출해서 바꿔줘야된다.
    PermanentWorker(const char *name, int money)
    : Employee(name), Salary(money){}
    int GetPay() const
    {
        return Salary; // 임시 객체 
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        // 불렀으면 어디 저장이 되야 우리한테 출력이 된다.
        cout << "Salary: "<< GetPay() << endl << endl;
    }
};
// Employee 부모 클래스를 상속받은 TemporaryWorker 자식 클래스
class TemporaryWorker : public Employee
{
    int workTime;
    int payPerHour;
public:
    // 세개 받아야하는 애가 왜 2개 밖에 안받나?.
    // 밑에서 0으로 디폴트 값으로 초기화 해주고있다
    TemporaryWorker(const char *name, int pay)
    : Employee(name), workTime(0), payPerHour(pay) {}
    void AddWorkTime(int time) // 일한 시간 추가
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime*payPerHour;
    }
    // 얘들은 애초에 겹칠 일이 없다. 얘는 얘꺼고 쟤는 쟤꺼고
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: "<< GetPay() << endl << endl;
    }
};
// PermanentWorker 부모 클래스를 상속받은 SalesWorker 자식 클래스
class SalesWorker : public PermanentWorker
{
    int salesResult;    // 월 판매실적
    double bonusRatio;  // 상여금 비율
    public:
        SalesWorker(const char *name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){}
        
        void AddSalesResult(int value)
        {
            salesResult += value;
        }
        
        int GetPay() const
        {
            return PermanentWorker::GetPay()
            + (int)(salesResult * bonusRatio);
        }
        // 함수 오버라이딩 - ||상속 관계에서||매서드 이름 같고||매개 변수 타입 같고||매개 변수 같고||
        // 부모 클래스에 있는 매서드는 자식 클래스의 매서드에 가려짐 - 재정의
        // 부모 클래스의 포인터로 접근해가지고 자식 클래스의 정보를 가져오려고 할 때도
        // 부모 매서드가 가려지고 자식 매서드가 작동하게 되어있다.
        // 실질적으로 중요한 타입은 객체 타입이다. 포인트 타입도 객체 타입을 따르는게 바람직하다.

        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout <<"salary: "<< GetPay() << endl<< endl;
        }
};
// 제어하는 기능을 핸들러라고 칭함.
// 직원 관리를 목적으로 설계된 컨트롤 클래스
class EmployeeHandler
{
        // Employee 타입으로(포인터 형) 빈 칸(이름 empList)을 50칸을 만들어
        // 객체를 저장 할 수 있다. 
        Employee* empList[50]; // 포인터 배열 - 포인터를 저장하는 배열임
        int empNum;
    public:
        // empNum 초기 값은 0이다. 디폴트 초기값
        EmployeeHandler() : empNum(0){}
        // Employee형 emp 값을 받아 - 전달 받은 객체
        void AddEmployee(Employee* emp) // Employee 포인터형
        {
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const
        {
            /*
            for (int i = 0 ; i< empNum; i++) {
                empList[i]->ShowSalaryInfo();
            }
            */
        }
        void ShowTotalSalary() const
        {
            int sum = 0;
            /*
            for (int i = 0 ; i < empNum; i++) {
                sum += empList[i]->GetPay();
            }
            */
            cout << "salary sum: "<< sum << endl;
        }
        // 소멸자 - 객체 소멸 [동적 할당 받은 애 해제]
        ~EmployeeHandler()
        {
            for (int i =0 ; i < empNum; i++) {
                delete empList[i];
            }
        }
};

int main()
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;
    
    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000)); // 메모리 동적할당
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    
    // 임시직 alba 객체 생성
    TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5); // 에로우 연산자 - 포인터를 통해 참조
    // 임시직 등록
    handler.AddEmployee(alba); // . = 객체를 통해서 데이터 참조

    // 영업직 seller 객체 생성
    SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    //영업직 등록
    handler.AddEmployee(seller);
    
    handler.ShowAllSalaryInfo();
    
    handler.ShowTotalSalary();
    
    return 0;
}

/* 배열 포인터 || 포인터 배열 */

/*
배열 포인터는 포인터인데 배열을 가리키는 포인터
포인터 배열은 배열인데 포인터로 이루어진 배열

1. 포인터 배열
int n1 = 10, n2 = 20, n3 = 30; 
int* ary[3] = {&n1, &n2, &n3} // & = 주소값
배열을 만들었는데 들어가는 요소값이 주소값.
그래서 int 뒤에 *붙여서 무슨 타입인지 알려주는것. - int형 주소값

2. 배열 포인터
int* pa = &a; - 나는 포인터를 선언할꺼야 
int ary[3] = {1, 2, 3};
int* pary = ary;  // 배열 포인터 = 배열이 1차원일 때 일반 포인터랑 똑같다.
int(* pary) = ary;  // 없어도 되는데 일반 포인터랑 구분이 안되니까 이렇게 표시만 해준거다.
주소를 저장 할 수 있는게 포인터 변수
포인터이기 때문에 주소가 들어가야된다. 근데 배열의 이름 자체가 주소
그냥 배열을 가리키기만 하면된다.
int arr[2][3] = {{1, 2, 3}, {4, 5, 6}} // 행, 열 3개의 원소를 가진 2차원 배열이다.
int(* parr)[3] = arr; // 괄호 친건 일차원 배열이구나 알 수 있음.
int *parr[3] = arr; // 이러면 햇갈린다. 열 값이 중요하다.
// 2차원 배열을 가리키는 배열 포인터
*/
