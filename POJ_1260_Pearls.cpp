#include<iostream>
using namespace std;
const int INF=1000000000;
int main()
{
	int nCases,i,j,categories,need[110]={0},price[110]={0},opt[110]={0},amount,min_sum,total_sum;
	
	cin>>nCases;
	while(nCases--)
	{
		cin>>categories;
		for(i=1;i<=categories;i++)
			cin>>need[i]>>price[i];
		total_sum=opt[0]=0;
		for(i=1;i<=categories;i++)
		{
			min_sum=INF;
			total_sum+=need[i];
			amount=total_sum;
			for(j=0;j<i;j++)
			{
				amount-=need[j];
				if(opt[j]+(amount+10)*price[i]<min_sum)
					min_sum=opt[j]+(amount+10)*price[i];
			}
			opt[i]=min_sum;
		}
		cout<<opt[categories]<<endl;
	}
	return 0;
}
