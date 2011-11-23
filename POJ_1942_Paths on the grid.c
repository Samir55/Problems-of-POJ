#include<stdio.h>
int main()
{
	__int64 m,n,i,min,max;
	__int64 sol;
	
	while(scanf("%I64d%I64d",&m,&n) && (m || n))
	{
		min=m>n?n:m;
		max=m+n-min;
		sol=1;
		for(i=1;i<=min;i++)
		{
			sol=sol*(max+i)/i;
		}
		printf("%I64d\n",sol);
	}

	return 0;
}
