#include <iostream>
using namespace std;
 
class SoBase{
private:
    int baseNum;
public:
    // 디폴트 생성자
    SoBase() : baseNum(20){
        cout << "SoBase()"<<endl;
    }
    // 인자 1개 짜리
    SoBase(int n) : baseNum(n){
        cout<<"SoBase(int n)" << endl;
    }
    void ShowBaseData(){
        cout << baseNum<<endl;
    }
};
/* SoDerived가 자식 클래스 접근 지정자 public의 SoBase 부모클래스를 물려받는다 */
class SoDerived : public SoBase{
private:
    int derivNum;
public:
    // 디폴트 생성자
    SoDerived():derivNum(30){
        cout << "SoDerived()"<<endl;
    }
    // 인자 1개 짜리
    SoDerived(int n) : derivNum(n){
        cout << "SoDerived(int n)" << endl;
    }
    // 인자 2개 짜리
    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2){ // 생성자를 직접 명시
        cout << "SoDerived(int n1, int n2)" << endl;
    }
    // 부모 클래스 값을 먼저 보여주고 자식 클래스 값을 보여준다.
    void ShowDerivData(){
        ShowBaseData();
        cout << derivNum << endl;
    }
};
 
int main(void){
    cout << "case1....." << endl;
    // 자식 클래스 객체 생성 디폴트
    SoDerived dr1;
    // 값 띄우기
    dr1.ShowDerivData();
    cout << "--------------" << endl;
    cout << "case2..... " << endl;
    // 두번째 자식 클래스 객체 생성 인자 1개
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "--------------" << endl;
    cout << "case3..... " << endl;
    // 세번째 자식 클래스 생성 인자 2개
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();
    return 0;
}
