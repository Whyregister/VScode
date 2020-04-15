#include <iostream>
#include <conio.h>

using namespace std;

string TalkTo(const string &TalkToId = "[随机玩家]",const string & Talk_Content= "[抖一抖");

string TalkTo(const string &TalkToId,const string & Takl_Content)
{
    return ">你对"+TalkToId+"发送了："+Takl_Content+"<";
}



int main ()
{
    string TalkToId;
    string Talk_Content;
    
    switch(getch())
    {
        case '1':
                cout << "输入发送对象名：" << endl;
                cin >> TalkToId ;
                cout << "输入发送内容：" << endl;
                cin >> Talk_Content;
                cout << TalkTo(TalkToId,Talk_Content) << endl;
                break;
        case '2':
                cout << TalkTo() << endl;
                break;
    }

    getch();
    
    return 0;

}