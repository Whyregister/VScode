// #include <iostream>
// #include <conio.h>
// #include "Landowener.h"
// #include "Student.h"
// #include "Integer.h"
// #include "Mystring.h"
// #include "MyVector.hpp"
// #include "Det.hpp"
// #include "Date.h"
// #include "windows.h"
// using namespace std;

// void Test2();
// void Test1();

// void Test6()
// {
//     MyVector<int> vec1(100,90);

//     vec1[3] = 1;
//     cout << vec1[3] << endl;
//     cout << vec1 << endl;    
// }

// void Test5()
// {
//     Mystring str1="你妈逼";
//     Mystring str2(str1);

//     cout << str1 << endl;
//     cout << str2 << endl;
    
//     str1 = str2 ;

//     cout << str1 << endl;
//     cout << str2 << endl;
// }

// void Test3()
// {
//     Integer Int1(857),Int2(520);

//     Int1 = Int2;
//     Int1 = Int1 + 112;

//     cout << Int1 << "哈哈" << endl;
//     cout << Int2;
// }
// void Test4()
// {
//     Integer Int(857);
//     cout << Int;
// }

// void Test1()
// {
//     Student * ptr_stu =new Student("迪丽热巴","微胖女孩");
//     ptr_stu->AddScore(23.3);
//     ptr_stu->AddScore(63.3);
//     ptr_stu->AddScore(33.3);
//     ptr_stu->AddScore(83.3);
//     ptr_stu->AddScore(73.3);

//     Student stu("小马哥","深圳");
//     stu.AddScore(56.3);
//     stu.AddScore(86.3);
//     stu.AddScore(56.3);
//     stu.AddScore(26.3);
//     stu.AddScore(16.3);

//     Student schoolar = ptr_stu->scholar(stu);
//     Student schoolar1 = stu.scholar(*ptr_stu);

//     cout << "学霸是：" << schoolar.ShowName() << schoolar.GetScoreTal() << "分" << endl;
//     cout << "学霸是：" << schoolar1.ShowName() << schoolar1.GetScoreTal() << "分" << endl;
//     delete ptr_stu;
// }

// void Test2(const int * ptr)
// {
//     int nam;
//     ptr = &nam;
// }

// void dettest()
// {
//         while (1)
//     {
//         Det<double> D;
//         cin >> D;
//         cout << endl;
//         cout << D;
//         cout << endl << '\n';
//     }

// }

// void DateTest()
// {
//     Date date(2000,2,29);

//     while(1)
//     {
//         system("cls");
//         cout << date + 1;
//         Sleep(60);
//     }
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