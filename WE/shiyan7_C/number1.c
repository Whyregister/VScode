#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int inputnumber();
int inputposition();
typedef struct link_list
{
    char number[30];
    char sex[20];
    char name [30];
    struct link_list *next;
} STU;

STU * creatlist()
{
    printf("Enter the information of students to create a linked list to store it,end with \'0\'\n");
    
    char number[30];
    char sex[20],name[30];

    STU *head,*p,*taital;
    head=(STU *)malloc(sizeof(STU));
    head->next=NULL;
    taital=head;
    if (!head)   
    {
    puts("error malloc!");
    exit (1);
    }


    puts("input number sex name");
    scanf("%s",number);
    while (*number!='0'&&scanf("%s%s",sex,name)==2)
    {
            p=(STU *)malloc(sizeof(STU));
            strcpy(p->number,number),strcpy(p->sex,sex),strcpy(p->name,name);
            p->next=taital->next;
            taital->next=p;
            taital=p;
            scanf("%s",number);
    }
    return head;
}

void outputlist(STU * p)
{

    if (!p)
    puts("without information!\n");
    while (p)
    {
        printf("number: %d  name : %s  sex: %s\n",p->number,p->name,p->sex);
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

int change(STU * head,int n,char *name,char *sex,char * number)
{
    STU * p=head->next;
    for (int i=1;i<n&&p;p=p->next,i++);
    strcpy(p->name,name);
    strcpy(p->number,number);
    strcpy(p->sex,sex);
    return 1;  
}

int  insert (STU * head,int n,char *name,char *sex,char * number)
{
    STU * p ,* pre=head;
    p=(STU *)malloc(sizeof(STU));
    strcpy(p->sex,sex);
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
    

int inputnumber(char * number)
{
    for (int i=0;i<11;i++)
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


int main ()
{
    STU * head=NULL;
    printf("1,insert\n2,delete\n3,search\n4,outputlist\n5,change\n");
    char c;
    int n;
    char name[30];
    char number[30];
    char sex[20];
    head=creatlist();
    if(head->next)
    puts("\nsuccess to creat!");
    while (1)
    {
while (1)
{
    c=getch();
    switch (c)
    {

    case '1':
            
            puts("input which position you want to insert");
            while (scanf("%d",&n),inputposition(n,head))
            {
                puts("error input!,without this position!");
            }  

            puts("the insert number!");
            while (fflush(stdin),scanf("%s",number),inputnumber(number))
            {
                puts("must bedigitals!");
            }


            puts("\nthe sex!");
            scanf("%s",sex);

            puts("the insert name!");
            scanf("%s",name);

            if(insert(head,n,name,sex,number))
            puts("\nsuccess!");
            else
            puts("\nfail!");     
            break;
    case '2':
            puts("input which position you want to delete");
            while (scanf("%d",&n),inputposition(n,head))
            {
                puts("error input!,without this position!input again!");
            }
            if(Delete(head,n))
            puts("success!");
            else
            puts("fail!");
            break;
    case '3': 
            fflush(stdin);
            puts("input the name of man you want to find");
            scanf("%s",name);
            if(search(head,name))
            printf("number:%s,sex:%s,name:%s",search(head,name)->number,search(head,name)->sex,search(head,name)->name);
            else
            puts("without this one");
            break;
    case '4':
                if (!head->next)
            {
                puts("without any information!");
            }
                else
            outputlist(head->next);
            
            break;

    case '5':
            puts("input which one you want to change");
            while (scanf("%d",&n),inputposition(n,head))
            {
                puts("error input!,without this position!input again!");
            }  

            puts("the number!");
            while (fflush(stdin),scanf("%d",number),inputnumber(number))
            {
                puts("must be digitals!");
            }
            puts("\nthe sex!");
            scanf("%s",sex);
            
            puts("the new name!");
            scanf("%s",name);
            
            if(change(head,n,name,sex,number))
            puts("success!");
            else
            puts("fail!");
            break;
    }

}
    
}
    return 0;
}