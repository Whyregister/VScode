
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