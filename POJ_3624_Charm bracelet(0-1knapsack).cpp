#include<iostream>
#include<cstdio>
#define MAXN 25000
using namespace std;
int w[MAXN],v[MAXN],opt[2][MAXN]={0};
int main()
{
	int i,j,n,m,min=MAXN,tmp;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{	
		scanf("%d%d",&w[i],&v[i]);
		if(w[i]<min)
			min=w[i];
	}
	for(i=1;i<=n;i++)
		for(j=min;j<=m;j++)
		{	
			opt[(i+1)%2][j]=opt[i%2][j];
			if(j>=w[i] && opt[i%2][j-w[i]]+v[i]>opt[(i+1)%2][j])
				opt[(i+1)%2][j]=opt[i%2][j-w[i]]+v[i];
		}
	printf("%d\n",opt[(n+1)%2][m]);
	system("pause");
	return 0;
}
