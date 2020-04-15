#include <iostream>
#include "Calendar.h"
#include <conio.h>
using namespace std;

int main()
{
    Calendar * ptr_cal = new Calendar(2020,3,26,17,19,0);
    
    cout << endl;
    ptr_cal->ShowCalendar();

    delete ptr_cal;

    getch();
    return 0;
}









// #include <iostream>
// #include <conio.h>
// #include "Carlo.h"
// using namespace std;
// int main ()
// {
//     Carlo c(40,1.2);

//     cout << "当前总价格 = " << c.GetCurrentTotalPrice() << endl;
//     cout << "当前总重量 = " << c.GetCurrentTotalWeight() << endl;
//     c.ShowBoxInfor();
//     cout << endl;

//     c.SellBox();
//     cout << "当前总价格 = " << c.GetCurrentTotalPrice() << endl;
//     cout << "当前总重量 = " << c.GetCurrentTotalWeight() << endl;
//     c.ShowBoxInfor();
//     cout << endl;

//     c.SetCarlo(20,4.3);
//     c.BuyBox();
//     cout << "当前总价格 = " << c.GetCurrentTotalPrice() << endl;
//     cout << "当前总重量 = " << c.GetCurrentTotalWeight() << endl;
//     c.ShowBoxInfor();
//     cout << endl;


//     Carlo d(1,1);
//     cout << "当前总价格 = " << d.GetCurrentTotalPrice() << endl;
//     cout << "当前总重量 = " << d.GetCurrentTotalWeight() << endl;
//     d.ShowBoxInfor();    


//     Carlo b(20,1.3);
//     cout << "当前总价格 = " << b.GetCurrentTotalPrice() << endl;
//     cout << "当前总重量 = " << b.GetCurrentTotalWeight() << endl;
//     b.ShowBoxInfor();    

//     getch();
//     return 0;
// }

// void VirsualFunPoint()
// {
//     Hero galon;
    
//     /**对象地址*/
//     int * ObjPtr = (int * )&galon;
//     cout << "对象地址：" << ObjPtr << endl;

//     /**虚拟函数列表地址*/
//     int * visListAddress = (int *) * (ObjPtr + 0);
//     cout << "隐藏成员：虚拟函数列表地址" << visListAddress << endl;

//     /**第一个虚拟函数地址*/
//     int * List1Address = (int * ) * (visListAddress + 0);
//     cout << "第一个虚拟函数地址" << List1Address << endl;

//     /**第二个虚拟函数地址*/
//     int * list2Address = (int *) * (visListAddress + 2);
//     cout << "第二个虚拟函数地址" << list2Address << endl;
                                        
//     void( * FunPtr)() = (void (*)())(List1Address);
//     FunPtr();

//     FunPtr = (void(*)()) (list2Address);
//     FunPtr();

//     Warrior sb;

//     /**对象地址*/
//     int * ObjPtr2 = (int *)&sb;
//     cout << "对象地址：" << ObjPtr2 << endl;

//     /**虚拟函数列表地址*/
//     int * virListPtr2 = (int *)*(ObjPtr2 + 0);
//     cout << "虚拟函数列表地址：" << virListPtr2 << endl;

//     /**第一个虚拟函数列表地址*/
//     int * virFunc1Ptr = (int *)*(virListPtr2+0);
//     cout << "第一个虚拟函数列表地址："  << virFunc1Ptr << endl;

//     /**第二个虚拟函数地址*/
//     int * virFunc2Ptr = (int * ) * ( virListPtr2 + 2);
//     cout << "第二个虚拟函数地址：" << virFunc2Ptr << endl;

//     /**第三个虚拟函数地址*/
//     int * virFunc3Ptr = (int *) * ( virListPtr2 + 4);
//     cout << "第三个虚拟函数地址：" << virFunc1Ptr << endl;


//     FunPtr = (void(*)())virFunc1Ptr;
//     FunPtr();

//     FunPtr = (void(*)())virFunc2Ptr;
//     FunPtr();


//     getch();
// }

// void VirsualFunPoint();
// void VirXigouTest()
// {
//     Warrior * G = new Warrior("Galon");

//     ADC * A = new ADC("Anxi");

//     G->Skill(*A);

//     A->Skill(*G);

//     A->~ADC();

//     delete G;
// }