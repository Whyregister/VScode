#include <stdio.h>
//指针函数
int * pow(int * a,int * b)
{
    *a+=1;
    return a;
}
int main ()
{
    int a,b;
    pow(&a,&b);
    printf("%d",*(pow(&a,&b)));
}