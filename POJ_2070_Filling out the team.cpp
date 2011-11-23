#include<iostream>
using namespace std;
int main()
{
	bool muti;
	int weight,strength;
	float speed;
	
	while(1)
	{
		muti=false;
		cin>>speed>>weight>>strength;
		if(!speed&&!weight&&!strength)
			break;
		else
		{
			if(speed<=4.5&&weight>=150&&strength>=200)
			{
				cout<<"Wide Receiver";
				muti=true;
			}
			if(speed<=6.0&&weight>=300&&strength>=500)
			{	
				if(muti)
					cout<<" Lineman";
				else
				{
					cout<<"Lineman";
					muti=true;
				}
			}
			if(speed<=5.0&&weight>=200&&strength>=300)
			{	
				if(muti)
					cout<<" Quarterback";
				else
				{
					cout<<"Quarterback";
					muti=true;
				}
			}
			if(!muti)
				cout<<"No positions";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
