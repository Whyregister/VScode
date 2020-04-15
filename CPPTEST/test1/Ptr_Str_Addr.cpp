#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    char ch = 'a';

    char * ptr_ch = &ch;//->char * str = {"hhh"};

    cout << ptr_ch <<'\t' << *ptr_ch << '\n' ;

    int num = 1;

    int * ptr_int = & num;

    cout << ptr_int << '\t' << *ptr_int<<'\n';

    getch();
    
    return 0;

}