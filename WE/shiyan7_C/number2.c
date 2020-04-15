#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
int inputnumber(char *);

typedef struct link_list
{
    char name [30];
    char number[12];
    struct link_list *next;
}STU;

STU * creatlist()
{
    printf("Enter the information of students to create a linked list to store it,end with \'0\'\n");
    
    char number[12],name[30];

    STU *head,*p,*taitl;
    head=(STU *)malloc(sizeof(STU));
    head->next=NULL;
    taitl=head;
    if (!head)   
    {
    puts("error malloc!");
    exit (1);
    }

    puts("input name");
    scanf("%s",name);
    while (name[0]!='0')
    {
    p=(STU *)malloc(sizeof(STU));
    strcpy(p->name,name);
    puts("please input his or her number!");
    while(fflush(stdin),scanf("%s",number),inputnumber(number))
    {
        puts("must be 11 digitals!");
    }
    strcpy(p->number,number);
    p->next=taitl->next;
    taitl->next=p;
    taitl=p;
    puts("input name");
    scanf("%s",name);
    }
    if(name[0]=='0'&&!head->next)
    puts("fail to creat list!");
    else
    {
    puts("success creat list!");
    }
    return head;
}

void outputlist(STU * p)
{
    if (!p)
    {
        puts("without any information!");
    }
    while (p)
    {
        printf("\nname : %s  telephone number: %s\n",p->name,p->number);
        p=p->next;
    }
}

STU * search(STU * head,char * name)
{

    STU * p=head->next;
    while (p)
    {
        if (strcmp(p->name,name)==0)
        {
            return p;
            p=p->next;
        }
        else
        {
            p=p->next;
        }
        
    }
    return p;
    
}

int Delete(STU * head,int n)
{
    STU * pre=head,*p=head->next;
    for (int i=1;i<n&&p;pre=pre->next,p=p->next,i++);
    pre->next=p->next;
    free(p);
    p=pre->next;
    return 1;
}

int change(STU * head,int n,char * name,char * number)
{
            STU * p=head->next;
            for (int i=1;i<n&&p;p=p->next,i++);
            strcpy(p->name,name);
            strcpy(p->number,number);
            return 1;    
}

int inputnumber(char * number)
{
    char  *num[]={"110","120","119"};
    int i;
    for (i=0;i<3;i++)
    {
        if(!strcmp(number,*(num+i)))
        return 0;
    }
    


    if(strlen(number)!=11) 
    {
        return 1;
    }
    for (i=0;i<11;i++)
    if(* (number+i)>57||*(number+i)<48) 
    {
        return 1;
    }
    return 0;

}

int inputposition(int n,STU * head)
{
    STU * p=head->next;
    for (int i=1;i<n&&p;p=p->next,i++);
    if(!p||n<=0) 
    
    return 1;
    
    else

    return 0;
}

int inputinsertposition(int n,STU * head)
{
    STU * p=head;
    for (int i=1;i<n&&p;p=p->next,i++);
    if(!p||n<=0) 
    
    return 1;
    
    else

    return 0;
}

int insert (STU * head,int n,char * name,char * number)
{
    STU * p ,* pre=head;
    p=(STU *)malloc(sizeof(STU));
    strcpy(p->name,name);
    strcpy(p->number,number);
    for(int i=1;i<n&&pre;i++,pre=pre->next);
        if(pre)
        {
            p->next=pre->next;
            pre->next=p;
            return 1;
        }
        else
        {
            free(p);
            return 0;
        }
        
}

int main ()
{
    STU * head;
    int n;
    char name[30];
    char number[30];
    printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");
    char c; 
    fflush(stdin);
    head=creatlist();
    while (1)


    {
        while (1)
    {


    c=getch();
    switch (c)
    {


    case '1':
            system("cls");
            printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");
            fflush(stdin);
            puts("\ninput which position you want to insert");
            if(scanf("%d",&n),inputinsertposition(n,head))
            {
                puts("\nerror input!,without this position!input the operation again!");
                break;
            }  

            puts("\nthe insert name!");
            scanf("%s",name);

            puts("\nthe insert telephone number!");
            while (fflush(stdin),scanf("%s",number),inputnumber(number))
            {
                puts("\nmust be 11 digitals!input again!");
            }

            if(insert(head,n,name,number))
            puts("\nsuccess!");
            else
            puts("\nfail!");     
            break;

    case '2':
            system("cls");
            printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");

            fflush(stdin);
            puts("\ninput which position you want to delete");
            if (scanf("%d",&n),inputposition(n,head))
            {
                puts("\nerror input!,without this position! input the operation again!");
                break;
            }
            if(Delete(head,n))
            puts("\nsuccess!");
            else
            puts("\nfail!");
            break;

    case '3':
            system("cls");
            printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");
            fflush(stdin);
            puts("\ninput the name of man you want to find");
            scanf("%s",name);
            if(search(head,name))
            printf("\nhave this one");
            else
            puts("\nwithout this one");
            break;
    case '4':
            system("cls");
            printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");
            fflush(stdin);
            outputlist(head->next);
            break;
    case '5':
            system("cls");
            printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");
            puts("\ninput which one you want to change");
            if (scanf("%d",&n),inputposition(n,head))
            {
                puts("\nerror input!,without this position ! input again!");
                break;
            }  

            puts("\nthe new name!");
            scanf("%s",name);

            puts("\nthe new telephone number!");
            while (fflush(stdin),scanf("%s",number),inputnumber(number))
            {
                puts("\nmust be 11 digitals!input again!");
            }
            if(change(head,n,name,number))
            puts("\nsuccess!");
            break;
    }

    }
    
    }
    return 0;
}