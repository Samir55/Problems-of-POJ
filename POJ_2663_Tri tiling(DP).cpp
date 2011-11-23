#include<iostream>
#include<cstdio>
#define MAXN 30+2
using namespace std;
long val[MAXN]={1,0,3};
int main()
{
	int n,i,j;
	
	for(i=4;i<=MAXN;i+=2)
		val[i]=4*val[i-2]-val[i-4];
	
	while(scanf("%d",&n) && n!=-1)
	{
		printf("%ld\n",val[n]);
	}
	return 0;
}
