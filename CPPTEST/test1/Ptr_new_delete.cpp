#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    int * ptr_int = new int;
    *ptr_int = 10;
    cout << *ptr_int << '\t' << ptr_int << endl;

    double * ptr_double = new double;
    *ptr_double = 20.0f;
    cout << *ptr_double << '\t' << ptr_double << endl;

    int * ptr_intArray = new int[3];
    //int * ptr_intArray2 = new int[3] = {1,2,3}; wrong
    for (int i=0 ; i<3; i++)
    *(ptr_intArray+i) = i;
    
    for (int i=0 ; i<3; i++)
    cout << *(ptr_intArray+i) <<'\t';
    cout << ptr_intArray << '\n' <<endl;
    
    delete ptr_int;
    delete ptr_double;
    delete ptr_intArray;

    cout << *ptr_int << '\t' << ptr_int << endl;
    cout << *ptr_double << '\t' << ptr_double << endl;
    
    for (int i=0 ; i<3; i++)
    cout << *(ptr_intArray+i) << '\t';
    cout << ptr_intArray <<endl;

    getch();
    
    return 0;

}