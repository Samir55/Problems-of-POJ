#include<iostream>
using namespace std;
int main()
{
	int nCases,x,y;
	
	cin>>nCases;
	while(nCases--)
	{
		cin>>x>>y;
		if(x==y)
			cout<<2*x-x%2<<endl;
		else if(x==y+2)
			cout<<x+y-x%2<<endl;
		else
			cout<<"No Number"<<endl;
	}
	system("pause");
	return 0;
}
