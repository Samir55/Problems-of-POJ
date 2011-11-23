#include<iostream>
using namespace std;
int main()
{
	__int64 nCigars,k,sum,remain,tmp;
	
	while(cin>>nCigars>>k)
	{
		sum=nCigars;
		remain=0;
		while(nCigars/k)
		{
			sum+=nCigars/k;
			nCigars=nCigars/k+nCigars%k;
		}
		cout<<sum<<endl;
	}
	return 0;
}
