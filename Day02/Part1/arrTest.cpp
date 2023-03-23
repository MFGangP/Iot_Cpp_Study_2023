#include <iostream>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};   // 배열 이름은 주소다
    printf("arr 전체 크기 : %d\n",sizeof(arr)); // arr 전체 크기 : 20
    int *pary = arr; // 원래 &가 있어야 오류가 안뜨는데 배열 이름이 주소라는 증거
    printf("arr 주소 : %p\n", arr); // 배열 이름으로만 주소 확인
    printf("arr[0] 주소 : %p\n", arr[0]); // 이거는 0번 방에 들어가있는 데이터를 읽어오는 형태
    printf("arr[0] 주소 : %p\n", &arr[0]); // 0번 방의 주소를 읽어와라
    // 배열 주소는 배열의 첫번째 방 주소랑 똑같다.
    printf("arr + 1 : %p\n", arr + 1); // arr[1] (두번째 방의 주소) int - 4 byte
    printf("arr[1] 주소 : %p\n", &arr[1]);

    printf("pary 주소 : %p\n", &pary); // 포인터 변수의 주소
    printf("pary의 값 : %p\n", pary); // 배열의 주소 값
    printf("pary[0]의 주소 : %p\n", &pary[0]); // 배열의 주소 값
    printf("pary[0]의 값 : %p\n", pary[0]); // 배열 [0] 인덱스 값
    printf("pary[0] : %p\n", *pary);
    printf("pary[1] : %p\n", *(pary +1));


    return 0;
}