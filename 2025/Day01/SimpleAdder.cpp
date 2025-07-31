#include <iostream>

int main(void){
    int val1;
    std::cout<<"첫 번째 숫자 입력: "; // 입력 버퍼에 저장
    std::cin>>val1; // 엔터치면 cin이랑 만남

    int val2;
    std::cout<<"두 번째 숫자 입력: ";
    std::cin>>val2;

    int result=val1+val2;
    std::cout<<"덧셈 결과: "<<result<<std::endl;
    return 0;
}