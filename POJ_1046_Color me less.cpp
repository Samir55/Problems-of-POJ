#include<iostream>
#include<cstdio>
#define MAXN 16
#define INF 60000
using namespace std;
int main()
{
	int R[MAXN],G[MAXN],B[MAXN],min,i,j,r,g,b,tag;
	
	for(i=0;i<MAXN;i++)
		cin>>R[i]>>G[i]>>B[i];
	while(1)
	{
		min=INF;
		cin>>r>>g>>b;
		if(r==-1)
			break;
		for(i=0;i<MAXN;i++)
			if((r-R[i])*(r-R[i])+(g-G[i])*(g-G[i])+(b-B[i])*(b-B[i])<min)
			{	
				min=(r-R[i])*(r-R[i])+(g-G[i])*(g-G[i])+(b-B[i])*(b-B[i]);
				tag=i;
			}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,R[tag],G[tag],B[tag]);
	}
	system("pause");
	return 0;
}
