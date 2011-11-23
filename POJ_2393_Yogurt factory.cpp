#include<iostream>
#include<cstdio>
#define MAXN 10000+20
#define INF 100000
using namespace std;
int main()
{
	int n,s,i,cnt,minPrice=INF,price,amount;
	__int64 totPrice=0;
	
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&price,&amount);
		if(minPrice+s*cnt<price)
		{		
			totPrice+=(minPrice+s*cnt)*amount;
			cnt++;
		}
		else
		{
			minPrice=price;
			cnt=1;
			totPrice+=minPrice*amount;
		}
	}
	printf("%I64d\n",totPrice);
	return 0;
}
