#include <iostream>
#include <conio.h>

using namespace std;
	
void change(int & ,int & );
	
void change(int & num1,int & num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}



int main ()
{
    int num1 = 1314, num2 = 520;

    change (num1,num2);

    cout << num1 << '\t' << num2 << endl;

    getch();
    
    return 0;

}