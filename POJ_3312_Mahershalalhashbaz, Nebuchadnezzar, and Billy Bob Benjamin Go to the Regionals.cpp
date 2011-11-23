#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAXLEN 80+2
#define MAXN 1000+10
using namespace std;
int main()
{
	char name[MAXLEN];
	int len[MAXN],caseCnt=0,i,j,n,k,front,rear,ifok;
	long sum;
	double average;

	while(scanf("%d%d",&n,&k) && (n||k))
	{
	        if ( caseCnt != 0 )
                        printf( "\n" );
		caseCnt++;
		front=sum=0;
		rear=-1;
		ifok=1;
		for(i=0;i<n;i++)
		{
			scanf("%s",name);
			len[i]=strlen(name);
		}
		sort(len,len+n);
		for(i=0;i<n && ifok;i++)
		{
			rear++;
			sum+=len[i];
			if((rear-front+1)%k==0)
			{
				average=sum/k;
				for(j=front;j<rear;j++)
					if(fabs(len[i]*1.0-average)>2)
					{
						ifok=0;
						break;
					}
				if(ifok && rear!=n-1)
				{
					front=rear+1;
					sum=0;
				}
			}
		}
		if(ifok)
			printf("Case %d: yes\n",caseCnt);
		else
			printf("Case %d: no\n",caseCnt);
	}
	return 0;
}
