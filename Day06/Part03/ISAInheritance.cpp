#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
    char owner[50];
public:
    // 인자 1개 짜리 생성자
    Computer(char *name)
    {
        strcpy(owner, name);
    }
    void Calculate()
    {
        cout << "요청 내용을 계산합니다." <<endl;
    }
};
// 자식클래스 NotebookComp가 Computer 부모 클래스를 받는데 public상속한다.
class NotebookComp : public Computer
{
    int Battery;
    public:
        // 이름을 부모 클래스에서 받아와서 부모 클래스 생성자로 초기화 시킨다.
        NotebookComp(char * name, int initChag)
        : Computer(name), Battery(initChag)
        {/*할 수 있으면 여기에서 초기화 했다니까?*/}
        void Charging() { 
            Battery += 5;
        }
        void UseBattery() { 
            Battery -= 1;
        }
        void MovingCal()
        {
            if (GetBatteryInfo() < 1) {
                cout << "충전이 필요합니다. " << endl;
            return;
            }
            cout << "이동하면서 ";
            Calculate();
            UseBattery();
        }
        int GetBatteryInfo() { 
            return Battery; 
        }
};
// 자식클래스 TabletNotebook가 NotebookComp 부모 클래스를 받는데 public상속한다.
class TabletNotebook : public NotebookComp
{
    char regstPenModel[50];
    public:
    // 받아오는 인자 이름, initChag은 NotebookComp에서 받아와서 부모 클래스 생성자로 초기화 하는데
    // 애초에 얘도 받아왔으니까 Computer 클래스에서 생성자를 받아와서 초기화를 해야겠네.
        TabletNotebook(char *name, int initChag, char *pen)
        : NotebookComp(name, initChag)
        {
            strcpy(regstPenModel, pen);
        }
        void Write(char *penInfo)
        {
            if (GetBatteryInfo() < 1) {
                cout << "충전이 필요합니다. " <<endl;
                return;
            }
            if (strcmp(regstPenModel, penInfo) != 0) {
                cout << "등록된 펜이 아닙니다. ";
                return;
            }
            cout << "필기 내용을 처리합니다. " <<endl;
            UseBattery();
        }
};

int main()
{
    // Computer > NotebookComp > TabletNotebook 이렇게 물려있다.
    // NotebookComp형의 nc 객체 생성
    NotebookComp nc("이수종", 5);
    // TabletNotebook 형의 tn 객체 생성
    TabletNotebook tn ("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}