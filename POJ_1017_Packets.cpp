#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,d,e,f,y,x;
	int u[4]={0,5,3,1};
	long ans;

	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF && (a||b||c||d||e||f))
	{
		ans=d+e+f+(c+3)/4;
		y=5*d+u[c%4];
		if(b>y)	ans+=(b-y+8)/9;
		x=36*ans-36*f-25*e-16*d-9*c-4*b;
		if(a>x)	ans+=(a-x+35)/36;
		cout<<ans<<endl;
	}
	return 0;
}
