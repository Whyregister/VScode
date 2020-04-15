#include <stdio.h>
#include <stdlib.h>

#include "conio.h"
#include "string.h"
typedef struct player
{
    char name [30];
    char password[20];
    int damage;
}Player;

void passwordinput(char *pass)
{
    fflush(stdin);
    
    char ch;
	int i=0;
   
    while((ch=getch())!='\r')
	{
		if (ch=='\b')
		{
              if (i>0)
		{
			printf("\b \b");
			i--;
		}
		else
		
        	putchar(7);
		
        }
		else
		{
			pass[i]=ch;
			printf("*");
			i++;
		}
	} 
	pass[i]='\0';

}

void regist()
{
    
    Player player1,player2;
    char password2[12];
    char name [30];
    puts("input you id !\n");
    scanf("%s",player1.name);
    FILE * fp;
    fp=fopen("D:\\nima.txt","r");
    fread(&player2,sizeof(Player),1,fp);
    while (1)
    {
        if(!strcmp(player1.name,player2.name))
        {
            printf("A user name already exists!continue to input!\n");
            scanf("%s",player1.name);
            rewind(fp);
        }
        else 
        if(!feof(fp))
        {
            fread(&player2, sizeof(Player), 1, fp);
        }
        else 
        break;
    }
    fclose(fp);

    puts("input you password!\n");
    passwordinput(player1.password);
    puts("\nConfirm you password!\n");
    passwordinput(password2);

    while (strcmp(password2,player1.password))
    {
    puts("The two passwords are not the same.input again!\n");
    passwordinput(player1.password);
    puts("\nConfirm you password!\n");
    passwordinput(password2);
    }

    fp=fopen("D:\\nima.txt","a");
    fwrite(&player1,sizeof(Player),1,fp);
    fclose(fp);
    puts("success register!");
    
}

void login()
{
    FILE * fp;

    Player player1,player2;

    
    puts("input you id\n");
    gets(player1.name);

    puts("input you password!");
    passwordinput(player1.password);

    fp=fopen("D:\\nima.txt","r");
    fread(&player2,sizeof(Player),1,fp);
    while (1)
    {
        if(!strcmp(player2.name,player1.name)&&!strcmp(player1.password,player2.password))
        {
            puts("\nsuccess to login!");
            break;
        }
        else
        {
            if(!feof(fp))
            fread(&player2,sizeof(Player),1,fp);
            else
            {
                puts("\nerror username or error password!\n");
                break;
            }
            
        }
        
    }


}

int main ()
{
    char password[20];

    //inputbox(password,11,"input your name");
    //passwordinput(password);
    //regist();
    login();
    FILE  *fp;

    Player player1;
    fp=fopen("D:\\nima.txt","r");
    fread(&player1,sizeof(Player),1,fp);
    printf("%s %s",player1.name,player1.password);
    //fputs(password,fp);
    fclose(fp);
    return 0;
}