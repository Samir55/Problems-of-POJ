#include<iostream>
#include<cstdio>
#define MAXN 10+2
#define INF -100
using namespace std;

int digit[MAXN]={0};

int main()
{
	int i=1,j,cnt=0;
	int n,remain,add;
	
	cin>>n;
	remain=n;
	while(remain>i)
	{
		i++;
		digit[cnt++]=i;
		remain-=i;
	}
	add=remain/cnt;
	remain%=cnt;
	for(i=0;i<cnt;i++)
	{
		if(i!=0)
		    cout<<" ";
		if(i<cnt-remain)
		    cout<<digit[i]+add;
		else if(i>=cnt-remain)
		    cout<<digit[i]+add+1;
	}
	cout<<endl;
//	system("pause");
	return 0;
}
