#include <stdio.h>

int setfile(char * filename)
{
    FILE  * fp;
    fp=fopen(filename,"r");
    if(fp)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        fclose(fp);
        fp=fopen(filename,"w");
        fclose(fp);
        return 0;
    }
    
}

int main ()
{
    char filename[20];
    FILE * fp;
    puts("input filename\n");
    scanf("%s",filename);
    if(setfile(filename))
    puts("this file is exsit");
    else
    puts("success to set!\n");
    return 0;

}