#include <iostream> 

namespace mystd
{
    using namespace std;
    class ostream
    {
        public:
            // 원래는 애들 전역 변수로 오버로딩 해야된다.
            // 저자가 그냥 자기만의 네임 스페이스를 만들어서 쓰는거임 그래서 작성 가능
            // 클래스 이름 :: 함수 이름 (입력 값)
            void ostream::operator<<(const char* str) // 문자열 시작 주소
            {
                // 출력
                printf("%s", str);
            }
            // << 출력 연산자
            void ostream::operator<<(char str)
            {
                printf("%c", str);
            }
            
            void ostream::operator<<(int num)
            {
                printf("%d", num);
            }
            
            void ostream::operator<<(double e)
            {
                printf("%g", e);
            }

            // ostream& endl(ostream& ostm) 함수를 인자로 전달받음
            // 함수포인터 - 함수도 포인터다.
            // 함수의 머리부분이랑 생긴게 똑같아야한다.
            // (*fp)가 함수의 머리 부분
            // ostream& (*fp)(ostream& ostm)
            void ostream::operator<<(ostream& (*fp)(ostream& ostm))
            {
                fp(*this);
            }
    };
	// endl 함수
    // 실행되면 함수는 코드 세그먼트에 저장이 된다. 
    // 함수 주소를 통해 찾아가는게 그게 함수 포인터다.
    // endl이 함수 머리 부분
	ostream& endl(ostream& ostm)
	{
		ostm << '\n'; // 객체는 자기자신 개행문자 실행 - 개행 시켜라
		fflush(stdout); // stdout은 출력 버퍼 - 버퍼 비우기
        // 버퍼 안에 입력되어있는 값이 다 비워졌으니까 지시자(다음 번 입력이 어디로 가야하는지 알려주는 애)가 맨 앞으로 간다.
        // 다음 데이터를 0번으로 입력 가능하게 만들어주는 애
        // 우리가 치는 키보드 입력값은 입력 버퍼에 저장 된다.
        // 입력 버퍼에 있는 값을 가져와서 읽어내는게 cin 
		return ostm;
        // 출력도 출력 버퍼에 저장된다, 출력에 관련되있는 코드를 만나면(호출) 콘솔창에 출력되는 것.
	}

	ostream cout; // 새로운 ostream 클래스에 있는 객체의 이름 
	// 객체 내에서 다양한 기본자료형 데이터를 대상으로 << 연산자 오버로딩을 하고 있다.
};

int main(void)
{
	// using 네임스페이스이름::요소 는
	// 네임스페이스 이름 없이도 사용하게 해줌
	// 지역적 using 선언
	using mystd::cout;
	using mystd::endl;

	cout << "Simple String"; // 정적 데이터 영역에 문자열이 저장이 된다. 첫 문자의 시작 주소를 포인터로 찾아감. 
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);

	return 0;
}