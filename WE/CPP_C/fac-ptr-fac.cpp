#include <stdio.h>

int add(int a,int b)
{
    return a+b;
}

int sub(int a ,int b)
{
    return a-b;
}
int (* cum(char c))(int,int )
{

    switch (c)

    {
    case '+':return add;
        break;
    case '-':return sub;
        break;
    default:printf("just input add and sub\n");
        break;
    }
}

main ()
{
    char c;
    int a,b;
    int (*p)(int ,int );
    puts("please input :");
    scanf("%d%c%d",&a,&c,&b);
    p=cum(c);
    printf("%d\n",p(a,b));
}