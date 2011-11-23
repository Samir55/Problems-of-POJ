#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 100
using namespace std;
int a[MAXN],b[MAXN],len_b,len_a;
int main()
{
	char str[MAXN];
	int i,j,exp;
	int len,posLast,posPoint,posFirst;
	void multiply(int*, int*);
	
	while(scanf("%s %d",str,&exp)!=EOF)
	{
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		posPoint=posLast=posFirst=-1;
		len_a=strlen(str);
		for(i=0;i<len_a;i++)
		{
			if(str[i]!='0' && str[i]!='.' && posFirst==-1)
				posFirst=i;
			if(str[i]!='0' && str[i]!='.' || (str[i]!='.' && posPoint==-1))
				posLast=i;
			if(str[i]=='.')
				posPoint=i;
		}
		for(i=posLast,j=0;i>=posFirst;i--)
		{
			if(str[i]=='.')
				continue;
			else
			{	
				b[j]=a[j]=str[i]-'0';
				j++;
			}
		}
		len_b=len_a=j;
		for(i=1;i<exp;i++)
			multiply(a,b);
		if(posPoint<posFirst)
		{
			printf(".");
			for(i=0;i<(posLast-posPoint)*exp-len_b;i++)
				printf("0");
		}
		for(i=len_b-1;i>=0;i--)
		{
			if(posPoint>posFirst && posPoint<posLast && i==(posLast-posPoint)*exp-1)
				printf(".");
			printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}

void multiply(int* a, int* b)
{
	int i,j,len;
	int c[MAXN];
	
	memset(c,0,sizeof(c));
	for(i=0;a[i]!=-1;i++)
		for(j=0;b[j]!=-1;j++)
			c[i+j]+=a[i]*b[j];
	len=i+j-1;
	for(i=0;i<len;i++)
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	if(c[len]!=0)
		len_b=len+1;
	else
		len_b=len;
	for(i=0;i<len_b;i++)
		b[i]=c[i];
	return ;
}
