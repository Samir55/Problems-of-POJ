#include<stdio.h>
int main()
{
	long start, end,length,sum=0;
	int n,i;
	
	while(1)
	{
		scanf("%ld%d",&length,&n);	
		sum=0;
		if(length==0&&n==0)
			return 0;
		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&start,&end);
			sum+=end-start+1;
		}
		printf("%ld\n",length-sum+1);
	}
	system("pause");
	return 0;
}
