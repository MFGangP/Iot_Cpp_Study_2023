#include <iostream>
int sum_num(int n1, int n2); // 함수 선언

// 함수 정의
int sum_num(int n1, int n2) // 입력을 만드는 방법 : (매개) 변수를 선언
{
	int res = n1 + n2;
	return res;
}
int main()
{
	int num1 = 10;
	int num2 = 20;

	int res = sum_num(num1, num2);
	std::cout<<"두 수의 합은 "<< res <<"입니다"<<std::endl;
	std::cout<<"두 수의 합은 "<< sum_num(num1, num2) <<"입니다"<<std::endl;
} 

// 입력과 출력이 있는 함수 출력은 return문으로 작성
	// std::cout<<"두 수의 합은 "<<res<<"입니다"<<std::endl

	// int sum_num;
	// int num1;
	// std::cout<<"첫번째 숫자를 입력해주세요";
	// std::cin>>num1;

	// int num2;
	// std::cout<<"두번째 숫자를 입력해주세요";
	// std::cin>>num2;

	// sum_num = num1 + num2;
	// std::cout<<"두 수의 합은 "<<sum_num<<"입니다"<<std::endl;

	// int a = 10;
	// int b = 20;
	// int res;
	// res = a + b;
	// std::cout << "res : "<< res << std::endl;

