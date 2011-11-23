#include<iostream>
#define MAXN 30+5
using namespace std;
int main()
{
	bool if_acheive;
	int nCus,i,order[MAXN];
	long sum,tmp;
	
	while((cin>>nCus) && nCus)
	{
		sum=tmp=0;
		if_acheive=false;
		for(i=0;i<nCus;i++)
		{	
			cin>>order[i];
			tmp+=order[i];
		}
		if(tmp%2)
		{
			cout<<"No equal partitioning."<<endl;
			continue;
		}
		for(i=0;i<nCus;i++)
		{
			sum+=order[i];
			if(sum==tmp/2)
			{
				if_acheive=true;
				break;
			}
		}
		if(if_acheive)
			cout<<"Sam stops at position "<<i+1<<" and Ella stops at position "<<i+2<<"."<<endl;
		else
			cout<<"No equal partitioning."<<endl;
	}
	return 0;
}
