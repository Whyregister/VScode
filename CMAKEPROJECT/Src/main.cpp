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

//     cout << "��ǰ�ܼ۸� = " << c.GetCurrentTotalPrice() << endl;
//     cout << "��ǰ������ = " << c.GetCurrentTotalWeight() << endl;
//     c.ShowBoxInfor();
//     cout << endl;

//     c.SellBox();
//     cout << "��ǰ�ܼ۸� = " << c.GetCurrentTotalPrice() << endl;
//     cout << "��ǰ������ = " << c.GetCurrentTotalWeight() << endl;
//     c.ShowBoxInfor();
//     cout << endl;

//     c.SetCarlo(20,4.3);
//     c.BuyBox();
//     cout << "��ǰ�ܼ۸� = " << c.GetCurrentTotalPrice() << endl;
//     cout << "��ǰ������ = " << c.GetCurrentTotalWeight() << endl;
//     c.ShowBoxInfor();
//     cout << endl;


//     Carlo d(1,1);
//     cout << "��ǰ�ܼ۸� = " << d.GetCurrentTotalPrice() << endl;
//     cout << "��ǰ������ = " << d.GetCurrentTotalWeight() << endl;
//     d.ShowBoxInfor();    


//     Carlo b(20,1.3);
//     cout << "��ǰ�ܼ۸� = " << b.GetCurrentTotalPrice() << endl;
//     cout << "��ǰ������ = " << b.GetCurrentTotalWeight() << endl;
//     b.ShowBoxInfor();    

//     getch();
//     return 0;
// }

// void VirsualFunPoint()
// {
//     Hero galon;
    
//     /**�����ַ*/
//     int * ObjPtr = (int * )&galon;
//     cout << "�����ַ��" << ObjPtr << endl;

//     /**���⺯���б��ַ*/
//     int * visListAddress = (int *) * (ObjPtr + 0);
//     cout << "���س�Ա�����⺯���б��ַ" << visListAddress << endl;

//     /**��һ�����⺯����ַ*/
//     int * List1Address = (int * ) * (visListAddress + 0);
//     cout << "��һ�����⺯����ַ" << List1Address << endl;

//     /**�ڶ������⺯����ַ*/
//     int * list2Address = (int *) * (visListAddress + 2);
//     cout << "�ڶ������⺯����ַ" << list2Address << endl;
                                        
//     void( * FunPtr)() = (void (*)())(List1Address);
//     FunPtr();

//     FunPtr = (void(*)()) (list2Address);
//     FunPtr();

//     Warrior sb;

//     /**�����ַ*/
//     int * ObjPtr2 = (int *)&sb;
//     cout << "�����ַ��" << ObjPtr2 << endl;

//     /**���⺯���б��ַ*/
//     int * virListPtr2 = (int *)*(ObjPtr2 + 0);
//     cout << "���⺯���б��ַ��" << virListPtr2 << endl;

//     /**��һ�����⺯���б��ַ*/
//     int * virFunc1Ptr = (int *)*(virListPtr2+0);
//     cout << "��һ�����⺯���б��ַ��"  << virFunc1Ptr << endl;

//     /**�ڶ������⺯����ַ*/
//     int * virFunc2Ptr = (int * ) * ( virListPtr2 + 2);
//     cout << "�ڶ������⺯����ַ��" << virFunc2Ptr << endl;

//     /**���������⺯����ַ*/
//     int * virFunc3Ptr = (int *) * ( virListPtr2 + 4);
//     cout << "���������⺯����ַ��" << virFunc1Ptr << endl;


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