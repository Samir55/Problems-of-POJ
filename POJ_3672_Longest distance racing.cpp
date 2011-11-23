#include<iostream>
using namespace std;
int main()
{
	bool flag=true;
	char road;
	int limit_time,distance_unit,up_time,flat_time,down_time,i,longest_distance=0;
	
	cin>>limit_time>>distance_unit>>up_time>>flat_time>>down_time;
	for(i=0;i<distance_unit;i++)
	{
		cin>>road;
		if(flag)
		{
			if(road=='u' || road=='d')
			{
				if(limit_time-up_time-down_time<0)
					flag=false;
				if(flag)
				{
					++longest_distance;
					limit_time-=(up_time+down_time);
				}
			}
			else
			{
				if(limit_time-2*flat_time<0)
					flag=false;
				if(flag)
				{
					++longest_distance;
					limit_time-=2*flat_time;
				}
			}
		}
	}
	cout<<longest_distance<<endl;
	system("pause");
	return 0;
}
