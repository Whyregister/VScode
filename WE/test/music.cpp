#include<stdio.h>
int main()
{
	int t,n,c,i,a;
	scanf("%d",&n);
	a=0;
	for(t=0;t<=n;t++)
	{
		for(i=0;i<=n;i++)
		{
			for(c=0;c<=n;c=c+3)
			{
			if	(t+c+i==n&&15*t+9*i+c==3*n)
			{
				printf("%d,%d,%d\n",t,i,c);
				a++;
			}
			}
		}
	}
	if(a==0)
	printf("without answer!\n");
	return 0;
}