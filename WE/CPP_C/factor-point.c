//函数指针
//用处，用函数做形参
//调用时，ptr_factor 与 （*ptr_factor)等价
#include <stdio.h>
int pow (int a,int b)
{
    return a*b;
}

int main()
{
    int a=1,b=4;
    int (* ptr_factor)(int,int );
    ptr_factor=pow;
    printf("%d",ptr_factor(a,b));
}