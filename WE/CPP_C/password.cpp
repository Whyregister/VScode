#include <stdio.h>
#include "conio.h"
#include "string.h"
void input (char * scrt)
{
	for (int i=0;i<20;i++)
	scrt [i]='\0';
}
int main ()
{
	char sour [20]="123456";
	char scrt [20],c;
	int i;
	//���������ж�
	do
	{
	puts("\n�������룺\n");
	input (scrt);
	i=0;
	while ((c=getch()),c!='\r')
	{
		if ('\b'==c)
		{
			if (i>0)
			{
				i--;
				printf("\b \b");
			}
			
		}
		else
		{
			scrt [i]=c;
			i++;
			putchar('*');
		}
	}
	
	} while (strcmp(sour,scrt)!=0);

	printf("��¼�ɹ�\n");
	
	return 0;
}