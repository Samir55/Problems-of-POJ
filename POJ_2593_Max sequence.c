#include<stdio.h>
#define MAXN 100000+100
#define INF -100000
long opt[MAXN]={INF},rev_opt[MAXN],max[MAXN]={INF};
int main()
{
	int nCases;
	long i,nNum,num[MAXN],sol;
	
	while(scanf("%ld",&nNum)!=EOF && nNum)
	{	
		sol=rev_opt[nNum+1]=INF;
		for(i=1;i<=nNum;i++)
		{	
			scanf("%ld",&num[i]);
			opt[i]=opt[i-1]+num[i]>num[i]?opt[i-1]+num[i]:num[i];
			max[i]=max[i-1]>opt[i]?max[i-1]:opt[i];
		}
		for(i=nNum;i>0;i--)
		{
			rev_opt[i]=rev_opt[i+1]+num[i]>num[i]?rev_opt[i+1]+num[i]:num[i];
			if(max[i-1]+rev_opt[i]>sol)
					sol=max[i-1]+rev_opt[i];
		}
		printf("%ld\n",sol);
	}
	return 0;
}
