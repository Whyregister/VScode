#include "stdio.h"
#include "stdlib.h"
typedef struct  student 
{
    char name[100];
    char sex[100];
    int score;
    struct student * next;
    /* data */
}Stu;

Stu * Listhead(Stu * head,int n)
{
    Stu * p;
    for (int i=0;i<n;i++)
    {
        p=(Stu * )malloc(n*sizeof(Stu));
        puts("input name你");
        scanf("%s",p->name);
        puts("input sex:");
        scanf("%s",p->sex);
        puts("input score:");
        scanf("%d",&p->score);
        p->next=head;
        head=p;
        if (!p)
        {
            printf("fail to malloc:");
            break;
            /* code */
        }
        
    }
    return head;
}

void  looklist(Stu * head,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d %s %s",head->score,head->name ,head->sex);
        head=head->next;
    } 
}
int main ()

{
    Stu * head=NULL;
    int n;
    scanf("%d",&n);
    head= Listhead(head ,n);
    looklist(head,n);
    return 0;
}