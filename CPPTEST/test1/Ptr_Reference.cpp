#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    const double & ref = 100;

    int num = 108;
    int& ref_num = num ;
    ref_num = 118;
    cout << &num <<'\t'<< &ref_num <<'\t' << ref_num <<endl;

    //等价于
    
    int * ref_num2 = &num;
    *ref_num2 = 118;
    cout << &num << '\t' << ref_num2 << '\t' << *ref_num2 <<endl;

    getch();
    
    return 0;

}