#include<iostream>
#include<cmath>
#define MAXN 20+5
using namespace std;
int main()
{
	int nCases,nPositions,i,place[MAXN],max,min;
	
	cin>>nCases;
	while(nCases--)
	{
		max=-1;
		min=5000;
		cin>>nPositions;
		for(i=0;i<nPositions;i++)
		{
			cin>>place[i];
			if(place[i]>max)
				max=place[i];
			if(place[i]<min)
				min=place[i];
		}
		cout<<(max-min)*2<<endl;
	}	
	return 0;
}
