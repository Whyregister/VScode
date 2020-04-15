#include <stdio.h>
#include <string.h>
char * fun (char  *str)
{
    char *p=str;
    while (*p)
    {
        if(*p == ' ')
            strcpy(p,p+1);      //不同地址，共同指针
        else
            p++;
        
    }
    return str;
}
int main ()
{
    char s[80],*q;
    printf("Please input a string :");
    gets(s);
    q = fun(s);
    printf("The result is :%s\n",q);
    return 0;
}