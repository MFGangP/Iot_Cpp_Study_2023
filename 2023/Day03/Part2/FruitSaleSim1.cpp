#include <iostream>
using namespace std;

class FruitSeller{
    // 정의
	private :   // 외부 접근 차단
    	int APPLE_PRICE; // 가격
        int numOfApples; // 개수
        int myMoney; // 돈
    // 행동
    public :    // 함수는 바깥에서 접근 해야되기 때문에 Public
    	void InitMembers(int price, int num, int money){
        	APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }
        int SaleApples(int money){
        	int num= money/APPLE_PRICE; // 총액에서 사과 가격 나누면 몇개 살 수 있는지 나옴.
        	numOfApples -= num;
            myMoney += money;
            return num;
        }
       void ShowSalesResult(){
       		cout<<"남은 사과 "<<numOfApples<<endl;
            cout<<"판매 수익 "<<myMoney<<endl;
        }
};

class FruitBuyer{	
    // 정의
	int myMoney; // 살 사람 돈, 클래스 안에서 생성된 변수는 private 안넣어도 기본적으로 private
    int numOfApples; //개수
    // 행동
    public :
    // 여기서 변수 초기화 클래스 안에서 해봐야 의미가 없다 할당 되기 전이라서.
    	void InitMembers(int money){
        	myMoney = money;
            numOfApples=0;
        }
        // 두개의 매개 변수 선언. 첫번째 참조자 두번째 int
        void BuyApples(FruitSeller &seller, int money){
        	numOfApples+=seller.SaleApples(money);
            myMoney -= money;
        }
        void ShowBuyResult(){
         	cout<<"현재 잔액 :"<<myMoney<<endl;
            cout<<"사과 개수 :"<<numOfApples<<endl;
            
        }
 };
 
 int main(void){
 	FruitSeller seller;
    // 여기서 초기화 해주는게 진짜
    seller.InitMembers(1000,20,0);
    FruitBuyer buyer;
    // 여기서 초기화 해주는게 진짜
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout<<"과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    return 0;
}