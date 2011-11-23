#include<stdio.h>
#define MAXN 100+10
int main()
{
	int i,j,numCounter=0;
	long num[MAXN],result[MAXN];
	int check(long);
	
	while(1)
	{
		scanf("%ld",&num[numCounter]);
		if(!num[numCounter])
			break;
		else
			numCounter++;
	}
	for(i=0;i<numCounter;i++)
		result[i]=check(num[i]);
	printf("PERFECTION OUTPUT\n");
	for(i=0;i<numCounter;i++)
		if(result[i]==1)
			printf("%5ld  ABUNDANT\n",num[i]);
		else if(result[i]==-1)
			printf("%5ld  DEFICIENT\n",num[i]);
		else
			printf("%5ld  PERFECT\n",num[i]);
	printf("END OF OUTPUT\n");
	system("pause");
	return 0;
}

int check(long num)
{
	int i;
	long sum=1,tmp;
	
	if(num==1)
		return -1;
	tmp=num;
	for(i=2;i<num;i++)
		if(0==num%i && num/i>i)
			sum=sum+i+num/i;
	if(num==sum)
		return 0;
	else
		return sum>num?1:-1;
}

