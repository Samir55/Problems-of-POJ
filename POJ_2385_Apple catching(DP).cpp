#include<iostream>
#include<cstdio>
using namespace std;
short opt[1002][32][2]={0},apple[1000+1];
int main()
{
	int t,w,i,j,k,max=0;
		
	scanf("%d%d",&t,&w);
	for(i=1;i<=t;i++)
		scanf("%d",&apple[i]);
	if(apple[1]==1)	
		for(j=0;j<=w;j++)
			opt[1][j][1]=1;
	else if(apple[1]==2)
		for(j=0;j<=w;j++)
			opt[1][j][2]=1;
	for(i=2;i<=t;i++)
	{
		for(j=0;j<=w;j++)
		{	
			for(k=1;k<3;k++)
			{
				opt[i][j][k]=opt[i-1][j][k]+(k==apple[i]);
				if(j<=w-1)
				{
					if(k==1 && opt[i-1][j+1][2]+(k==apple[i])>opt[i][j][k])
						opt[i][j][k]=opt[i-1][j+1][2]+(k==apple[i]);
					else if(k==2 && opt[i-1][j+1][1]+(k==apple[i])>opt[i][j][k])
					opt[i][j][k]=opt[i-1][j+1][1]+(k==apple[i]);
				}
				if(opt[i][j][k]>max)
					max=opt[i][j][k];
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
