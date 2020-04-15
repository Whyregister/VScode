#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    double * ptr_double;
    int * ptr_int;

    cout<<ptr_double++<< '\t' <<ptr_double++<<endl;

    cout<<ptr_int++   << '\t' << ptr_int++<<endl;

    getch();
    
    return 0;

}