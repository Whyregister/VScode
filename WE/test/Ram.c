#include <stdio.h>
#include "stdlib.h"
//栈、堆、全局（静态存储区）、常量区、代码区
int y;
int add(int a,int b)//a,b->stack,c->static,add->代码区
{
    static char c=0;
    printf("%p\n%p\n%p\n%p\n\n",&a,&b,&c,&y);
    return a+b;
}
int * x;
int main ()
{
    int a;
    int b;
    int * m=NULL;
    int * n=NULL;
    m=(int *)malloc(4*sizeof(int));
    n=(int *)malloc(4*sizeof(int));//heap
    add(a,b);
    printf("stack:%p %p\n",&a,&b);
    printf("heap:%p %p\n",m,n);//nixu
    printf("static:%p\n",&y);
    printf("interger:%p %p\n",&"abc",&"abca");//nixu
    printf("代码区：%p %p",add,main);
}