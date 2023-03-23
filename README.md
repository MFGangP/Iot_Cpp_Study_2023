# iot_cpp_study

# 1일차

- printf, scanf -> cout::, cin::
- Function Overloading(함수 오버로딩 - 다중정의)
- Default Value(디폴트 값)
- inline(인라인 함수)
- namespace(이름 공간) 조금

# 2일차

- namespace(이름 공간) - using namespace std;
- 메모리 공간
    - 코드 세그먼트, 데이터 세그먼트
        - 동적 데이터
        - 힙
        - 정적 데이터
        - 코드 
- bool 타입
- signed, unsigned, 부호비트, 비트연산자 (<<, >>)
- Call by Value(변수), Call by Reference(참조자 - 변수의 별칭), 더블 포인터 연산

역시 포인터는 볼 때마다 햇갈린다. 더블 포인터에서 포인터 하나를 빼면 그 전 주소값이 나오나? 아찔하네 c++

# 3일차

- Part1
    - Call by Reference(참조자 - 변수의 별칭)
    - new & delete <== malloc & free 대신
    - 동적 할당
    - C++에서 C 표준함수 호출하기

- Part2
    - 구조체 Struct, Class
    - enum(열거형)
    ```cpp
    enum
    {
        ID_LEN  = 20,
        MAX_SPD  = 200,
        FUEL_STEP  = 2,
        ACC_STEP  = 10,
        BRK_STEP  = 10
    };

    ```
    - Class(클래스)와 Object(객체)
    ```c
    class Myclass{
         // 외부의 접근을 불허한다. (95%)
        private:
            int private_val;
        // 외부 접근 가능
        public:
            int public_val;
        // 상속에서만 접근 가능
        protected:
            int protected_val;
        public: // 멤버 함수 밖에서 쓰려면 public 무조건 써줘야된다.
            // 멤버 변수 값 바꾸는 법
            void set(int an)
            {
                private_val = an;
            }
            void get()
            {
                cout << "public_val : "<< public_val << endl;
                cout << "private_val : "<< private_val << endl;
            }
        };
    ```
    - 객체지향 프로그래밍
    - Infomation Hiding (정보은닉)
