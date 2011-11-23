#include<iostream>
using namespace std;
int main()
{
	int i,j,k,l,limit,cube=0;
	
	cin>>limit;
	for(i=6;i<=limit;i++)
	{
		for(j=2;j<i;j++)
		{
			for(k=j;k<i;k++)
			{
				for(l=k;l<i;l++)
				{
					if(i*i*i==j*j*j+k*k*k+l*l*l)
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")\n";
				}
			}
		}
	}
	system("pause");
	return 0;
}
