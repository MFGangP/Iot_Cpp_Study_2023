#include <iostream>
using namespace std;
/*
메모리 동적 할당 (C type)
*/
int main()
{
    int* arr;
    int size; // char 에 127 이상 넣으면 에러 뜬다. 그땐 - VISUAL STUDIO에서 scanf_s를 써서 늘려줘야된다. 
    printf("배열 방의 개수 : ");
    scanf("%d", &size); // C는 scanf로 입력 받으면 주소 연산자가 와야된다.
    
    arr = (int*)malloc(sizeof(int) * size); // 힙(heap) 영역에 메모리 할당받았다
            // 리턴 타입 + malloc + 크기
            //(void*) 아직 어떤 형태로 받을 지 안 정해졌을 때
            // 타입은 맞춰주면 된다. 
    printf("%d개의 숫자를 입력하세요.\n", size);
    // 요소 입력 받기
    for (int i = 0; i < size; i++){
        printf("%d번째 숫자 : ", i + 1);
        scanf("%d", arr + i); // scanf는 주소연산자가 나와야하는데 배열 자체가 주소를 가리키고 있음.
                              // 배열주소에 + 1을 하고 있는 것
    }
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
        printf("%d\n", *(arr + i));
    }
    free(arr); // 할당 받았으니까 반환 해야된다.
    // arr = malloc(sizeof(int));
    return 0;
}