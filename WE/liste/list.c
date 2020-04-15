#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct list
{
    char name[30];
    struct list * next;
}STU;

char * input (char * name)
{
    puts("input your name !\n");
    scanf("%s",name);
    return name;
}

int output(STU * student)
{
    STU * p=student;
    while(p)
    {
        printf("%s",p->name);
        p=p->next;
    }
    return 0;
}

STU * creatlist(STU * student)
{   
        char name[30];
        STU * p,*end;
        puts("end with '0' \n");
        input(name);
        while(name[0]!='0')
        {

        if(!student)
        {
            student=(STU *)malloc(sizeof(STU));
            strcpy(student->name,name); 
            end=student; 
            input(name);
        }
        else 
        {
            p=(STU * )malloc(sizeof(STU));
            strcpy(p->name,name);
            end->next=p;
            end=p;
            input(name);
        }

        }
     
        end->next=NULL;
        return student;
}
int main()
{
    char c;
    STU * student=NULL;
    puts("\n1.creat\n2.output\n");
    while(1)
    {
    
    c=getch();
    switch(c)
    {
        case '1':student=creatlist(student);
        break;
        case '2':output(student);
        break;
        default:
        break;
    }
    
    }

}