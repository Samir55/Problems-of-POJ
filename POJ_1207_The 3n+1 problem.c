#include<stdio.h>
#define MAXN 10002
short length[3000*MAXN]={1,1};
short CalculateLength(long n)
{
	short tmp;
	
	if(length[n]!=0)
		return length[n];
	else
	{
		if(n%2!=0)
			tmp=CalculateLength(3*n+1)+1;
		else
			tmp=CalculateLength(n/2)+1;
		return tmp;
	}
}
int main()
{
	long i,j,max,begin,end,tmp,tmp_begin,tmp_end;
	
	for(j=2;j<MAXN;j++)
		if(!length[j])
			length[j]=CalculateLength(j);
	while(scanf("%ld%ld",&begin,&end)!=EOF)
	{
		max=0;
		if(end<begin)
		{
			tmp_begin=end;
			tmp_end=begin;
		}
		else
		{
			tmp_begin=begin;
			tmp_end=end;
		}
		for(i=tmp_begin;i<=tmp_end;i++)
			if(length[i]>max)
				max=length[i];
		printf("%ld %ld %ld\n",begin,end,max);
	}
	system("pause");
	return 0;
}

