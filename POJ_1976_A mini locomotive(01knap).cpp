#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 50000+10
using namespace std;

int coach[MAXN],num[MAXN];
long knap[MAXN][4]={0};

int main()
{
	unsigned int i,j,nCase,nCoach,nPull;
	
	scanf("%d",&nCase);
	while(nCase--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&nCoach);
		for(i=1;i<=nCoach;i++)
			scanf("%d",&coach[i]);
		scanf("%d",&nPull);
		for(i=1;i<=nCoach-nPull+1;i++)
   			for(j=i;j<i+nPull;j++)
				num[i]+=coach[j];
		for(i=1;i<=nCoach-nPull+1;i++)
		{
			for(j=1;j<=3;j++)
			{
				if(i<=nPull)
					knap[i][j]=(knap[i-1][j]>(knap[0][j-1]+num[i]))?knap[i-1][j]:(knap[0][j-1]+num[i]);
				else
					knap[i][j]=(knap[i-1][j]>(knap[i-nPull][j-1]+num[i]))?knap[i-1][j]:(knap[i-nPull][j-1]+num[i]);
			}
		}
		printf("%ld\n",knap[nCoach-nPull+1][3]);
	}
	return 0;
}
