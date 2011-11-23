#include<iostream>
#include<cstdio>
#define MAXN 100+10
#define INF 10000000

int manu[MAXN];
struct Device
{
	int band;
	int price;
}device[MAXN][MAXN];
int compare(const void *p1, const void *p2)
{
	return (*(struct Device*)p1).price-(*(struct Device*)p2).price;
}
using namespace std;

int main()
{
	int i,j,k,l,nCases,nDevices;
	int minBand,tot_price;
	double ans;
	
	cin>>nCases;
	while(nCases--)
	{
		ans=-1;
		cin>>nDevices;
		for(i=0;i<nDevices;i++)
		{
			cin>>manu[i];
			for(j=0;j<manu[i];j++)
				cin>>device[i][j].band>>device[i][j].price;
			qsort(device[i],manu[i],sizeof(struct Device),compare);
		}
		for(i=0;i<nDevices;i++)
			for(j=0;j<manu[i];j++)
			{
				minBand=device[i][j].band;
				tot_price=device[i][j].price;
				for(k=0;k<nDevices;k++) 
				{
					if(k==i) continue;
					for(l=0;l<manu[k];l++)
						if(device[k][l].band>=minBand)
							break;
					if(l==manu[k])
					{
						minBand=0;
						break;
					}
					tot_price+=device[k][l].price;
				}
				if((double)minBand/(double)tot_price>ans)
					ans=(double)minBand/(double)tot_price;
			}
		printf("%.3lf\n",ans);
	}
	return 0;
}
