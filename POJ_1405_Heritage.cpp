#include<iostream>
#include<cstdio>
#include<cstring>

#define MAXN 50000+10
using namespace std;

char num[20][MAXN]={"2"};

int main()
{
	void multiply();
	int i,j,n;
	
	multiply();
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			printf("%s\n",num[i]);
	}
	
	return 0;
}

void multiply()
{
	int i,j,k,a[MAXN]={0},tmp[MAXN];
	long len;
	
	for(i=0;i<17;i++)
	{
		memset(tmp,0,sizeof(tmp));
		len=strlen(num[i]);
		for(j=len-1;j>=0;j--)
			a[len-j-1]=num[i][j]-'0';
		for(j=0;j<len;j++)
			for(k=0;k<len;k++)
			{	
				if(j==0)
					tmp[j+k]+=(a[j]-1)*a[k];
				else 	
					tmp[j+k]+=a[j]*a[k];
			}
		len=j+k-1;
		for(j=0;j<len;j++)
			if(tmp[j]>=10)
			{
				tmp[j+1]+=tmp[j]/10;
				tmp[j]%=10;
			}
		if(tmp[len])
			len++;
		for(j=0;j<len;j++)
			num[i+1][len-j-1]=tmp[j]+'0';
		num[i+1][len-1]++;
		num[i+1][len]='\0';
	}
	return ;
}
