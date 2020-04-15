#include <iostream>
#include <string>
using namespace std;
int main ()
{
    int day=1;
    int dayofweeek = 2;
    int i=1;
    cout<<"一\t二\t三\t四\t五\t六\t日\n"<<endl;
    //第一天位置
    while (dayofweeek>1)
    {
        cout<<'\t';
        dayofweeek--;
        i++;
    }
    while (day<32)
    {
        cout<<day<<'\t';
        if (i>=7)
        {
            i=1;
            cout<<'\n';
        }
        else
        {
            i++;
        }
        
        day++;
    }
    return 0;   
         
}