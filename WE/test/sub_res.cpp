#include <stdio.h>
#include <string.h>
int delete_sub_str(const char *str,const char *sub_str,char *result_str)
{
	int i,j,k,s,c=0;
	int n=strlen(str),m=strlen(sub_str);
	for (i=0;i<n;i++)	*(result_str+i)=*(str+i);
	for ( i=0;i<n;i++)
	if (*(result_str+i)==*sub_str)
	{
		s=1;
		for (j=1;j<m;j++)
		
		if (*(result_str+i+j)!=*(sub_str+j))	
		{
		s=0;
		break;
		}
		
		
		if (s)
		{
			for (k=0;k<=n-i-m;k++)	*(result_str+i+k)=*(result_str+i+k+m);
			n-=m;
			c++;
			*(result_str+n+1)='\0';
		}
	}
		return c;
}

main ()
{
	printf("�����ַ���:"); 
	char str[100];
	char sub_str[10];
	char result_str[100]={'\0'};
	gets(str);
	printf("����ɾ�ĵ��ַ���:");
	gets(sub_str);
	printf("ɾ����%d���Ӵ�\n",delete_sub_str(str,sub_str,result_str));
	puts(result_str);
}
