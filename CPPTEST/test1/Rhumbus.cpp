#include <iostream>
#include <cmath>
using namespace std;
 int main ()
 {
	int n,i,j;
	while(scanf("%d",&n)!=1||n<=0||n%2==0)
	{
		fflush(stdin);
		printf("wrong input\n");
	}

	  
	for (i=1;i<=n;printf("\n"),i++)
	{
		for (j=1;j<=abs(i-n/2-1);printf(" "),j++);
		for (j=1;j<=abs(n-2*abs(i-n/2-1));printf("*"),j++);
	}
    return 0;
 }