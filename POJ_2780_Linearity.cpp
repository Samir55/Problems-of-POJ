#include<iostream>
#include<algorithm>
#define MAXN 1000+20
#define INF 2147483647
using namespace std;
double slope[MAXN];
double x[MAXN],y[MAXN];
int main()
{
	int i,j,n,nCases,counter,ans,max;
	double tmp;
	
	while(cin>>nCases)
	{
		max=1;
		for(i=0;i<nCases;i++)
			cin>>x[i]>>y[i];
		for(i=0;i<nCases;i++)
		{
			ans=counter=0;
			
			for(j=i+1;j<nCases;j++)
			{
				if(x[i]==x[j])
					slope[counter++]=INF;
				else
					slope[counter++]=(y[j]-y[i])/(x[j]-x[i]);
			}
			sort(slope,slope+counter);
			tmp=slope[0];
			for(j=0;j<counter;j++)
			{
				if(slope[j]==tmp)
				{	
					ans++;
					if(ans>max)
						max=ans;
				}
				else
				{
					if(ans>max)
						max=ans;
					tmp=slope[j];
					ans=1;
				}
			}
		}
		cout<<max+1<<endl;	
	}
	return 0;
}
