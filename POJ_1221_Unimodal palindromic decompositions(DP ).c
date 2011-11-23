#include<stdio.h>
#define MAXN 300+20
__int64 opt[MAXN][MAXN]={0};
int main()
{
	int i,j,n;
	
	for(j=0;j<MAXN;j++)
		opt[0][j]=1;
	for(i=1;i<MAXN;i++)
		for(j=i/2+1;j<=i;j++)
			opt[i][j]=1;
	for(i=2;i<MAXN;i++)
		for(j=i/2;j>0;j--)
			opt[i][j]=opt[i-2*j][j]+opt[i][j+1];
	while(scanf("%d",&n)&&n)
	{
		printf("%d %I64d\n",n,opt[n][1]);
	}
	return 0;
}
