#include<stdio.h>
#include<string.h>
#define MAXN 50000+100

typedef struct mon
{
	long x;
	long y;
}Monkey;

int cmp(const void* p1, const void* p2)
{
	if ((*(Monkey*)p1).x>(*(Monkey*)p2).x) return 1;
	else if((*(Monkey*)p1).x<(*(Monkey*)p2).x)	return -1;
	else return (*(Monkey*)p1).y>(*(Monkey*)p2).y?1:-1;
}


int main()
{
	Monkey monkey[MAXN];
	long nMonkeys,nKings,i,maxY;
	
	while(1)
	{
		nKings=0;
		scanf("%ld",&nMonkeys);
		if(!nMonkeys)
			break;
		memset(monkey,0,sizeof(monkey));
		for(i=0;i<nMonkeys;i++)
			scanf("%ld %ld",&monkey[i].x,&monkey[i].y);
		qsort(monkey,nMonkeys,sizeof(Monkey),cmp);
		maxY=monkey[nMonkeys-1].y-1;
		for(i=nMonkeys-1;i>-1;i--)
			if(monkey[i].y>maxY)
			{
				maxY=monkey[i].y;
				nKings++;
			}
		printf("%ld\n",nKings);
	}
	return 0;
}
