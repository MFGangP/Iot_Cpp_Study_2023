#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Girl; // Girl 이라는 이름이 클래스 이름이라는걸 선언

class Boy
{
    private:
        int height;
        friend class Girl;

    public:

    Boy(int len) : height(len){}
    void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
    private:
        char phNum[20];
    public:
        Girl(const char * Num)
        {
            strcpy(phNum, Num);
        }
        void ShowYourFriendInfo(Boy &frn);
        friend class Boy;   // Boy 클래스에 대한 friend 선언
};

void Boy :: ShowYourFriendInfo(Girl &frn)
{
    cout << "Her phone number : "<< frn.phNum<<endl;
}

void Girl :: ShowYourFriendInfo(Boy &frn)
{
    cout << "His phone number : "<< frn.height<<endl;
}

int main(void)
{
    Boy boy(170);
    Girl girl("010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
    return 0;
}
