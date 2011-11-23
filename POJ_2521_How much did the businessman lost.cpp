#include<iostream>
using namespace std;
int main()
{
	long n,m,p,c;
	
	while(1)
	{
		cin>>n>>m>>p>>c;
		if(!n&&!m&&!p&&!c)
			break;
		cout<<n+p-m<<endl;
	}
	system("pause");
	return 0;
}
