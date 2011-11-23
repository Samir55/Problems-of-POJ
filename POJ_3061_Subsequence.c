#include<stdio.h>
#define MAXN 100000+10
long list[MAXN],max;
int main()
{
	__int64 nCases,nNum,tot_sum,sub_sum,i,front,rear,sol;
	
	scanf("%I64d",&nCases);
	while(nCases--)
	{
		max=rear=front=sub_sum=0;
		scanf("%I64d%I64d",&nNum,&tot_sum);
		for(i=0;i<nNum;i++)
		{
			scanf("%ld",&list[i]);
			if(list[i]>max)
				max=list[i];
			sub_sum+=list[i];
		}
		if(sub_sum<tot_sum)
		{
			printf("0\n");
			continue;
		}
		else if(max>=tot_sum)
		{
			printf("1\n");
			continue;
		}
		else
		{
			sub_sum=0;
			sol=MAXN;
			while(front<=rear && rear<=nNum)
			{
				if(sub_sum>=tot_sum)
				{
					if(rear-front+1<=sol)
						sol=rear-front;
					sub_sum-=list[front];
					front++;
				}
				else
				{
					sub_sum+=list[rear];
					rear++;
				}
			}
			printf("%I64d\n",sol);
		}
	}
	return 0;
}

