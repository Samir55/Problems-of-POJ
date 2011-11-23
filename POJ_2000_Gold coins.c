#include<stdio.h>
int main()
{
	int n,i,j,coin,count;
	long sum;
	
	while(1)
	{
		sum=0;
		count=coin=1;
		scanf("%d",&n);
		if(!n)
			break;
		for(i=1;i<=n;i++)
		{
			if(!count)
				count=++coin;
			sum+=coin;
			count--;
		}
		printf("%d %ld\n",n,sum);
	}
	system("pause");
	return 0;
}
