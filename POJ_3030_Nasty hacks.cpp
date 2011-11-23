#include<iostream>
using namespace std;
int main()
{
	int nCases;
	long r,e,c;
	
	cin>>nCases;
	while(nCases--)
	{
		cin>>r>>e>>c;
		if(e-c>r)
			cout<<"advertise"<<endl;
		else if(e-c==r)
			cout<<"does not matter"<<endl;
		else
			cout<<"do not advertise"<<endl;		
	}
	return 0;
}
