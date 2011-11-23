#include<stdio.h>
int main()
{
	int nCases,i,caseCount,n;
	__int64 num[80]={1,2};
	
	for(i=2;i<=50;i++)
		num[i]=num[i-1]+num[i-2];
	scanf("%d",&nCases);
	caseCount=0;
	while(nCases--)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n%I64d\n\n",++caseCount,num[n]);
	}
	system("pause");
	return 0;
}
