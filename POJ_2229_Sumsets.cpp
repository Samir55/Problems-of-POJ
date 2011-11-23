#include<iostream>
#include<cstdio>
#define MAXN 1000000+1
using namespace std;

long long ans[MAXN]={1,1};

int main()
{
	unsigned long i;
	long n,dif=1;
	
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		    ans[i]=ans[i-1];
		else
		    ans[i]=ans[i-2]+ans[i/2];
		ans[i]%=1000000000;
	}
	printf("%lld\n",ans[n]);
	
//	system("pause");
	return 0;
}
