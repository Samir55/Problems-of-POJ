#include<stdio.h>
#define MAXN 100
int main()
{
	int n,q,i,schedule[MAXN+10],freeDay,day,max;
	
	while(1)
	{
		scanf("%d %d",&n,&q);
		if(!n&&!q)
			break;
		memset(schedule,0,sizeof(schedule));
		max=0;
		while(n--)
		{
			scanf("%d",&freeDay);
			while(freeDay--)
			{
				scanf("%d",&day);
				schedule[day]++;
			}
		}
		for(i=1;i<MAXN+10;i++)
			if(schedule[i]>schedule[max]&&schedule[i]>=q)
				max=i;
		printf("%d\n",max);
	}
	system("pause");
	return 0;
}
