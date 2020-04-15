#include <stdio.h>
#define mul(a,b)    a*b
main()
{
    FILE *fp;
    fp=fopen("d:\\nima.txt","wr");
    fprintf(fp,"%d",mul(4,5));
    fprintf(fp,"%d",mul(4,5));
    fscanf(fp,"%d");
    fclose(fp);
}