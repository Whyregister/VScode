#include <iostream>
#include <conio.h>

using namespace std;

int & test1(int & num1 ,int & num2)
{
    num1++;
    num2++;
}

int & test2(int & num1 ,int & num2)
{
    num1++;
    num2++;
    return num1;
}

int main ()
{
    int num1 = 10;
    int num2 = 20;
    int & ref_1 = test1(num1,num2);
    cout << ref_1 << '\t' << num2 << endl;

    int & ref_2 = test2(num1,num2);
    cout << ref_2 << '\t' << num1 << endl;
    
    test2(num1,num2) = 250;
    cout << ref_2 << '\t' << num1 << endl;

    getch();
    
    return 0;

}