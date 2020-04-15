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
    char filename1[20],filename2[20];
    FILE * fp1,*fp2;

    puts("input filename\n");
    scanf("%s",filename1);
    if(setfile(filename1))
    puts("this file is exsit\n");
    else
    puts("success to set!\n");

    puts("input filename\n");
    scanf("%s",filename2);
    if(setfile(filename2))
    puts("this file is exsit\n");
    else
    puts("success to set!\n");

    char f;
    fp1=fopen(filename1,"a");
    fp2=fopen(filename2,"r");

    while (!feof(fp2))
    {
        f=fgetc(fp2);
        fputc(f,fp1);
    }
    fclose (fp1);
    fclose (fp2);
    return 0;

}