#include <stdio.h>

typedef union seat
{
    int num;
    char T[40];
}Seat;
typedef struct shcoolmate
{
    char name[50]; 
    char job;
    Seat where;
    /* data */
}Schoolmate;
int main()
{
    Schoolmate mate1;
    scanf("%s",mate1.name);
    getchar();
    scanf("%c",&mate1.job);
    switch (mate1.job)
    {
    case 'T':scanf("%s",mate1.where.T);
        break;
    case 'S':scanf("%d",&mate1.where.num);
        break;
    }
    printf("%s %c",mate1.name,mate1.job);
     switch (mate1.job)
    {
    case 'T':printf("%s",mate1.where.T);
        break;
    case 'S':printf("%d",mate1.where.num);
        break;
    }
    return 0;
}
