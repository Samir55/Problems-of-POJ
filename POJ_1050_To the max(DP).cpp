#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 100+10
#define INF -10000
using namespace std;
int matrix[MAXN][MAXN],sum[MAXN],opt[MAXN]={0};
int main()
{
	int i,j,k,len,ans;
	
	while(scanf("%d",&len)!=EOF)
	{
		ans=INF;
		for(i=1;i<=len;i++)
			for(j=1;j<=len;j++)
				scanf("%d",&matrix[i][j]);
		for(i=1;i<=len;i++)
		{
			for(k=1;k<=len;k++)
				sum[k]=0;
			for(j=i;j<=len;j++)
			{
				for(k=1;k<=len;k++)
				{	
					sum[k]+=matrix[j][k];
					opt[k]=(opt[k-1]+sum[k])>sum[k]?(opt[k-1]+sum[k]):sum[k];
					if(opt[k]>ans)
						ans=opt[k];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
