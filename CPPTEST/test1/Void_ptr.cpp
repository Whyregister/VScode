#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    double num = 3.3;
    double * ptr_num1 = &num;

    void   * ptr_num2 = &num;
    
    cout << boolalpha;
    cout <<(ptr_num1 == ptr_num2) << endl;

    double * ptr_num3 = (double *)ptr_num2;
    cout << ptr_num3;


    // *ptr_num2 = 888;//wrong 

    getch();
    
    return 0;

}