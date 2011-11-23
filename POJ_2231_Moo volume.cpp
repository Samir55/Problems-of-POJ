#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 10000+10
using namespace std;

long long loc[MAXN]={0},sum,sub;

int main()
{
	int i;
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		sub=sum=0;
		for(i=1;i<=n;i++)
		    scanf("%lld",&loc[i]);
		sort(loc+1,loc+n+1);
		for(i=1;i<=n;i++)
		    sum+=loc[i]-loc[1];
		sub=sum;
		for(i=1;i<=n-1;i++)
		{
			sub+=(2*i-n)*(loc[i+1]-loc[i]);
			sum+=sub;
		}
		printf("%lld\n",sum);
	}
//	system("pause");
	return 0;
}
