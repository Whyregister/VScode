#include <iostream>
#include <conio.h>
using namespace std;
template<typename unConfirm,typename unConfirm2> void change(unConfirm & ,unConfirm2 & );

template<typename unConfirm,typename unConfirm2> void change(unConfirm & a,unConfirm2 & b)
{
    unConfirm temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename unConfirm> void sort(unConfirm * Array_name,int Len)
{
    for(int i = 0; i < Len ; i++)
    {    
    for (int j=0; j < Len - i - 1 ; j++)
    {
        if (Array_name[j] < Array_name[j+1])
        change(Array_name[j],Array_name[j+1]);
    }
    }
}
template<typename unConfirm> void output(unConfirm * Array_name,int Len)
{
    for ( int i = 0 ;i < Len ; i++)
    cout << Array_name[i] << '\t';
    cout << endl;
}

int main ()
{
    int Array_int[] = {1,3,4,54,5};

    sort(Array_int,sizeof(Array_int)/sizeof(int));
    output(Array_int,sizeof(Array_int)/sizeof(int));

    double Array_double[] = {1.23, 324.343 ,343.343,343.345};
    sort(Array_double,sizeof(Array_double)/sizeof(double));
    output(Array_double,sizeof(Array_double)/sizeof(double));  
    return 0;

}
