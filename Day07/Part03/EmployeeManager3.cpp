#include <iostream>
#include <cstring>
using namespace std;
// 최상위 부모 클래스
class Employee
{
    char name[100];
public:
    Employee(const char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: "<< name << endl;
    }
};
// Employee 부모 클래스를 상속받은 PermanentWorker 자식 클래스
class PermanentWorker : public Employee
{
    int Salary;
public:
    PermanentWorker(const char *name, int money)
    : Employee(name), Salary(money){}
    int GetPay() const
    {
        return Salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "Salary: "<< GetPay() << endl << endl;
    }
};
// Employee 부모 클래스를 상속받은 TemporaryWorker 자식 클래스
class TemporaryWorker : public Employee
{
    int workTime;
    int payPerHour;
public:
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
    // 함수 오버라이딩 - ||상속 관계에서||매서드 이름 같고||매개 변수 타입 같고||매개 변수 같고||
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
        
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout <<"salary: "<< GetPay() << endl<< endl;
        }
};
// 직원 관리를 목적으로 설계된 컨트롤 클래스
class EmployeeHandler
{
        // Employee형으로(포인터 형) 빈 칸(이름 empList)을 50칸을 만들어 
        Employee* empList[50];
        int empNum;
    public:
        // empNum 초기 값은 0이다.
        EmployeeHandler() : empNum(0){}
        // Employee형 emp 값을 받아
        void AddEmployee(Employee* emp)
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
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    
    // 임시직 alba 객체 생성
    TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    // 임시직 등록
    handler.AddEmployee(alba);

    // 영업직 seller 객체 생성
    SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    //영업직 등록
    handler.AddEmployee(seller);
    
    handler.ShowAllSalaryInfo();
    
    handler.ShowTotalSalary();
    
    return 0;
}