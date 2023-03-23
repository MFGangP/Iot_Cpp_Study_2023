#include <iostream>
using namespace std;
/*
메모리 동적 할당 (C++ type)
*/
int main()
{
    int* arr;
    int size; // char 에 127 이상 넣으면 에러 뜬다. 그땐 - VISUAL STUDIO에서 scanf_s를 써서 늘려줘야된다. 
   
    cout << "배열의 개수를 입력하세요 $:" << endl;
    cin >> size;

    arr = new int [size]; // arr을 인트형태의 방 몇개로 만들거냐 

    for(int i = 0; i < size; i++){
        cout<< i + 1 <<"번째 숫자 $: ";
        cin >> arr[i];
    }

    free(arr); // 할당 받았으니까 반환 해야된다.
    // arr = malloc(sizeof(int));
    return 0;
}