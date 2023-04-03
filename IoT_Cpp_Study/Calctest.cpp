// 계산기 클래스 생성
#include <iostream>
#include <string>
using namespace std;

int main()
{
    double x;
    const char* cper;
    double y;
    char temp[50];

    const char* separator_add = "+";
    const char* separator_sub = "-";
    const char* separator_mul = "*";
    const char* separator_div = "/";

    cout << "Calculator Console Application\n" << endl;
    cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;
    cout << "Press \"ctrl + c\" to exit the progtram\n" << endl;
    cout << "input >> ";
    cin >> temp; // 임시 배열

    string str = temp; // 나누기 위해 string 타입 변환

    int cur_position = 0; // 커서 위치
    int position; // 

    if (str.find(separator_add) != string::npos)
    {
        cper = separator_add;
        while ((position = str.find(separator_add, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            // cout << result << endl;
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << x + y << endl;
    }
    else if (str.find(separator_sub) != string::npos)
    {
        cper = separator_add;

        while ((position = str.find(separator_sub, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << x - y << endl;
    }
    else if (str.find(separator_mul) != string::npos)
    {
        cper = separator_add;

        while ((position = str.find(separator_mul, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << x * y << endl;
    }
    else if (str.find(separator_div) != string::npos)
    {
        cper = separator_add;

        while ((position = str.find(separator_div, cur_position)) != string::npos)
        {
            int len = position - cur_position;
            string result = str.substr(cur_position, len);
            x = stod(result);
            cur_position = position + 1;
        }
        string result = str.substr(cur_position);
        y = stod(result);
        cout << x / y << endl;
    }
    return 0;
}