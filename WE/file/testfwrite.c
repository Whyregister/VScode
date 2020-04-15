#include <stdio.h>

typedef struct student 
{
    char name[30];
    char sex[20];
}STU;
int main ()
{
    STU student1;
    FILE * fp;
    fp=fopen ("D:\\hh","wb+");

   /* for (int i=0;i<3;i++)
    {
    puts("name ,sex\n");
    scanf("%s%s",student1.name,student1.sex);
    fwrite(&student1,sizeof(STU),1,fp);
    }*/

    fclose(fp);
}