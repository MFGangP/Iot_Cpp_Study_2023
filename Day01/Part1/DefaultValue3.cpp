#include <iostream>
int BoxVolume(int length=1, int width=1, int height=1); 
// 이게 아래에 있으면 위에서 순서대로 읽어내려오니까 불가능
// 함수 선언

int main(void)
{
    std::cout<<"[3, 3, 3] : "<<BoxVolume(3, 3, 3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<BoxVolume(5, 5)<<std::endl;
    std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
    std::cout<<"[D, D, D] : "<<BoxVolume()<<std::endl;

    return 0;
}

int BoxVolume(int length, int width, int height) // 디폴트 값은 함수의 선언 부분에서만 표현할 수 있다.
{
    return length*width*height;
}
