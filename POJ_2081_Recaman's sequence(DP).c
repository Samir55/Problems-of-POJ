#include<stdio.h>
#define MAXN 500000
int flag[100*MAXN+10]={1};
long i,k,rec[MAXN+5]={0};
int main()
{
	for(i=1;i<=MAXN;i++)
	{
		if(rec[i-1]-i>0&&!flag[rec[i-1]-i])
		{
			rec[i]=rec[i-1]-i;
			flag[rec[i]]=1;
		}
		else
		{
			rec[i]=rec[i-1]+i;
			flag[rec[i]]=1;
		}
	}
	while(1)
	{
		scanf("%d",&k);
		if(k==-1)
			break;
		printf("%ld\n",rec[k]);
	}
	system("pause");
	return 0;
}
