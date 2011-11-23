#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1000+10
using namespace std;
int opt_dec[MAXN]={-1},opt_acc[MAXN]={-1};
int main()
{
	int n,i,j,maxPeople,max_dec,max_acc;
	double height[MAXN]={0},rev_height[MAXN]={0};
	
	while(scanf("%d",&n)!=EOF)
	{
		maxPeople=-1;
		for(i=1;i<=n;i++)
		{	
			scanf("%lf",&height[i]);
			rev_height[n-i+1]=height[i];
			opt_acc[i]=opt_dec[i]=1;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=i-1;j++)
			{
				if(height[j]<height[i] && opt_acc[j]+1>opt_acc[i])
					opt_acc[i]=opt_acc[j]+1;
				if(rev_height[j]<rev_height[i] && opt_dec[j]+1>opt_dec[i])
					opt_dec[i]=opt_dec[j]+1;
			}
		for(i=1;i<=n;i++)
		{
			max_acc=max_dec=0;
			for(j=i-1;j>=0;j--)
				if(height[j]<=height[i] && opt_acc[j]>max_acc)
					max_acc=opt_acc[j];
			for(j=n-i;j>=0;j--)
				if(height[j]<=height[n-i+1] && opt_dec[j]>max_dec)
					max_dec=opt_dec[j];
			if(maxPeople<max_dec+max_acc+1)
				maxPeople=max_dec+max_acc+1;
		}	

		printf("%d\n",n-maxPeople);
	}
	return 0;
}
