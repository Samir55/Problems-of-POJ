#include<stdio.h>
int main()
{
	long n,caseCount=0;
	__int64 sum,start,end;
	
	scanf("%d",&n);
	while(n--)
	{
		caseCount++;
		scanf("%I64d %I64d",&start,&end);
		sum=(end-start+1)*(start+end)/2;
		printf("Scenario #%ld:\n%I64d\n\n",caseCount,sum);
	}
	system("pause");
	return 0;
}
