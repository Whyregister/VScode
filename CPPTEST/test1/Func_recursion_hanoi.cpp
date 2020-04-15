#include <iostream>
#include <conio.h>

using namespace std;


template<typename unConfirm> void HanoiMove(const unConfirm Ini ,const unConfirm Obj)
{
    cout << Ini << "->" << Obj << endl;
}

template<typename unConfirm> void HanoiSelve(const int count ,const unConfirm Ini,const unConfirm medium, const unConfirm Obj)
{
    if(count == 1 )
    HanoiMove(Ini ,Obj);
    else
    {
    HanoiSelve(count - 1,Ini,Obj,medium);
    HanoiMove(Ini , Obj);
    HanoiSelve(count - 1,medium,Ini,Obj);
    }
}

int main ()
{
    HanoiSelve(10,"艾欧尼亚","诺克萨斯","德玛西亚");
    getch();
    return 0;

}