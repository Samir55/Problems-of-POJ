#include<stdio.h>
#define MAX_N 1000
int main()
{
	int n,maxLen[MAX_N+10]={0},num[MAX_N+10]={0},i,j,max;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	maxLen[0]=1;
	for(i=1;i<n;i++)
	{
		max=0;
		for(j=0;j<i;j++)
		{
			if(num[j]<num[i])
			{
				if(maxLen[j]>max)
					max=maxLen[j];
			}
		}
		maxLen[i]=max+1;
	}
	max=0;
	for(i=0;i<n;i++)
		if(max<maxLen[i])
			max=maxLen[i];
	printf("%d\n",max);
	system("pause");
	return 0;
}
