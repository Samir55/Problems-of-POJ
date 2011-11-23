#include<iostream>
#include<cstring>
#define MAXN 100+20
#define INF -100
using namespace std;
int opt[MAXN][MAXN],flowers[MAXN][MAXN];
int main()
{
	long nKinds,nVases,i,j,k,max;
	
	while(cin>>nKinds>>nVases)
	{
		memset(opt,INF,sizeof(opt));
		memset(flowers,0,sizeof(flowers));
		for(i=1;i<=nKinds;i++)
			for(j=1;j<=nVases;j++)
				cin>>flowers[i][j];
		if(nKinds==1)
		{
			max=INF;
			for(j=1;j<=nVases;j++)
				if(flowers[1][j]>max)
					max=flowers[1][j];
			cout<<max<<endl;
			continue;
		}
		for(j=1;j<=nVases;j++)
			opt[nKinds][j]=flowers[nKinds][j];
		for(i=nKinds-1;i>0;i--)
		{
			for(j=i;j<=i+nVases-nKinds;j++)
			{
				max=INF;
				for(k=j+1;k<=nVases;k++)
				{
					if(opt[i+1][k]>max)
						max=opt[i+1][k];
				}
				opt[i][j]=max+flowers[i][j];
			}
		}
		for(j=1;j<=nVases;j++)
			if(opt[1][j]>max)
				max=opt[1][j];
		cout<<max<<endl;
	}
	return 0;
}
