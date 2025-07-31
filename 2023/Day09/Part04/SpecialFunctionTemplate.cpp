#include <iostream>
#include <cstring>
using namespace std;
 
template <typename T>
T Max(T a, T b){
    return a > b ? a : b;
}
// 특정한 자료형일때 특별한 활동을 하게 만들고 싶으면
// 키워드가 없으면 그냥 함수 만들어놓은 것.
template <> // 이렇게 쓰면 특정 자료형을 바로 정해줘야 된다.
char* Max(char* a, char* b){
    cout << "char* Max<char*>(char* a, char* b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
};
template<>
const char* Max(const char* a, const char* b){
    cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
    return strcmp(a, b) > 0 ? a : b;
}
 
int main(void){
    cout << Max(11, 15)             << endl;
    cout << Max('T', 'Q')           << endl;
    cout << Max(3.5, 7.5)           << endl;
    cout << Max("Simple", "Best")   << endl;
 
    char str1[] = "Simple";
    char str2[] = "Best";
    cout << Max(str1, str2)         << endl;
    return 0;
}