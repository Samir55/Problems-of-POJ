#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 5000+20
#define INF 1000000
using namespace std;

long opt[MAXN]={0},stock[MAXN],total[MAXN];

int main()
{	
	int nDays,i,j,pre;
	long max_len,ans;
	
	scanf("%d",&nDays);
	for(i=1;i<=nDays;i++)
		scanf("%ld",&stock[i]);
	nDays++;total[0]=1;
	stock[nDays]=-1;stock[0]=INF;
	for(i=1;i<=nDays;i++)
	{
		pre=-1;
		for(j=i-1;j>=0;j--)
		{
			if(stock[j]>stock[i])
			{
				if(opt[j]+1==opt[i])
				{
					if(stock[j]==pre)	continue;
					total[i]+=total[j];
					pre=stock[j];	
				}
				else if(opt[j]+1>opt[i])
				{
					opt[i]=opt[j]+1;
					total[i]=total[j];
					pre=stock[j];
				}
			}
		}
	}
	printf("%ld %ld\n",opt[nDays]-1,total[nDays]);system("pause");
	return 0;
}
