# iot_cpp_study

# 1일차

- printf, scanf -> cout::, cin::
- Function Overloading(함수 오버로딩 - 다중정의)
- Default Value(디폴트 값)
- inline(인라인 함수)
- namespace(이름 공간) 조금

 선언 부분에 있는 기호들은 그냥 말그대로 기호다
 선언 부분 이후에 쓰이는건 그냥 이름 자체로 쓴다.
 [& xx=] 참조자 별명, 시간 복잡도를 줄이기 위해서 씀 가리키기만 하니까, 얘는 기호
 [* xx=] 포인터 주소 가리키는 애로 만들어, 얘는 기호
 선언부 이후에 왼쪽에 있든 오른쪽에 있든 그건 연산자.
 [= *xx] 주소에 존재하는 값(데이터가 배정 되어있는 칸 그 자체)를 반환해 (역참조) 널포인터 역참조하면 머리 깨짐
 [= &xx] 주소를 반환해

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
        - https://dayday-kim.tistory.com/5
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
    ```cpp
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

# 4일차

- 클래스 
    - Infomation Hiding (정보은닉) 나머지
        - const
    - Encapsulation (캡슐화)
    - Constructor(생성자)와 Destructor(소멸자)
        - 동적 할당 해제
        ```cpp
         MyClass(char aId, int aAge, const char* aName) : id(aId), age(aAge)
        {
            int len = strlen(aName) + 1;
            // 동적 할당을 하고 해제를 해야하는데 안하고 해제해서 오류 뜸
            name = new char[len];
            strcpy(name, aName);
        }
        ~MyClass()
        {
            delete []name; // 클래스 안에서 이름 넣는다고 쓴 heap 영역 해제
            cout << "call destructor!" << endl;
        }
        ```

# 5일차

- 클래스와 배열, this 포인터
    - 객체 배열
    - 객체 포인터 배열
    - this 포인터
- Copy Constructor(복사생성자)
    - 디폴트 복사생성자
    - 깊은 복사, 얕은 복사
    - 복사 생성자의 호출 시점 (어려움 확실하게 알아야됌)
        - 기존 객체를 이용해서 새로운 객체 생성
        - 함수 호출(Call_by_Value)시 객체를 인자로 전달
        - 객체를 반환 (참조형 X)

# 6일차

- friend와 static 그리고 const
    - const(값 못바꾸게 고정시킨다.)
    - friend(정보 은닉을 해치니 안쓰는게 좋다.)
    - static(전역,지역 특징을 골고루 가짐)
    - mutable(const 무효화)
- Inheritance(상속)
    - 부모클래스, 자식클래스
    - 상속의 문법적 이해
    - Protected 선언 및 3가지 형태의 상속
    - 상속을 위한 조건 (백수는 사람이야 아니야 ㄹㅇㅋㅋ)

# 7일차

- Inheritance(상속)
    - 상속을 위한 조건 (IS-A 관계의 상속)
- 상속과 다형성
    - 객체 포인터 변수
    - 포인터 배열, 배열 포인터
- Virtual Function (가상함수)
    - 순수 가상함수, 추상 클래스
    - 다형성
    ```cpp
        class First {
            public:
                // void MyFunc(){ cout << "FirstFunc" << endl; }
                // virtual을 쓰면 얘를 상속하는 자식의 오버라이딩 함수들도 자동으로 설정된다.
                virtual void MyFunc(){ cout << "FirstFunc" << endl; }
        };
        class Second : public First {
            public:
                virtual void MyFunc(){ cout << "SecondFunc" << endl; }
        };
        class Third : public Second {
            public:
                virtual void MyFunc(){ cout << "ThirdFunc" << endl; }
        };
        int main(void){
            Third * tptr = new Third(); // 자기 자신의 객체를 가리키는 형태
            Second * sptr = tptr; // 부모 클래스가 자식 클래스를 가리키는 형태
            First * fptr = sptr; // 객체 타입 포인터가 -> 자식클래스 가리키는 형태
            // 셋다 Third 얘를 가리킴 셋다 오버라이딩 된 결과가 나온다
            fptr->MyFunc(); // 포인터로 접근 할 때 애로우 씀, 매서드 호출
            sptr->MyFunc(); // 객체 포인터 자료형에 따라 접근 할 수 있는 범위가 정해진다.
            tptr->MyFunc(); // 읽어오는 대상이 달라짐 부모 객체 포인터를 가지고 자식 객체를 가리키더라도
                            // 나는 (자식 데이터, 메서드)를 가져오고싶다 하면 Virtual을 쓰는거다.
            delete tptr;
            return 0;
        }
    ```

# 8일차
- 가상 소명자와 참조자의 참조 가능성
    - 가상 소멸자 
- 다중상속 (넘어감 잘못 상속 받으면 코끼리가 날아다님)
- 연산자 오버로딩
    - 연산자 오버로딩의 이해와 유형
        - 기본 오버로딩 사용 = 생성자, 멤버 함수
            - 멤버함수에 의한 연산자 오버로딩
            - 전역함수에 의한 연산자 오버로딩
        - 단항 연산자의 오버로딩
- 연산자 오버로딩 2
    - 대입 연산자의 오버로딩
    
# 9일차

- 동적할당, 소멸자, 얕은 복사, 깊은 복사, 복사생성자 복습
    ```cpp
        public:
            // 생성자, 디폴트 초기화, 콜론 초기화
            Person(const char* aname, int abirthday = 19990909) : birthday(abirthday) 
            {
                // 입력 받은 값 + NULL 값
                int len = strlen(aname) + 1;
                // 힙 - 동적할당
                name = new char[len]; // 얘가 있으니까 복사생성자 만드는것
                strcpy(name, aname); // 얕은 복사로도 복사는 되니까
            }

            void ShowPerson()
            {
                cout << "이름 : " << name << endl;
                cout << "생일 : " << birthday << endl;
                cout << "이름 주소 값 : %p" << &name << " - 생일 주소 값 : %p" << &birthday << endl;
            }

            // 깊은 복사
            // 값으로 같은 클래스 형태의 값을 받는데
            // 포인터로 참조하는 대상까지 깊게 복사
            Person(const Person& ref) : birthday(ref.birthday)
            {
                name = new char[strlen(ref.name) + 1]; // 힙
                strcpy(name, ref.name); 
            }

            ~Person()
            {
                cout << "heap 영역 해제" << endl;
                delete name;
            }
    ```
- String 클래스의 디자인
    - C++의 표준과 표준 String 클래스
    - 문자열 처리 클래스의 정의
- 템플릿(Template)에 대한 이해와 함수 템플릿
    - 템플릿(붕어빵 틀)
        - 함수 템플릿
        - 클래스 템플릿
        - 클래스 템플릿의 특수화
- Try, Catch 예외처리
- Cast 연산자
    - static
    - const
    - dynamic
    - reinterpret