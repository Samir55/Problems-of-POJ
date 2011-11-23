#include<stdio.h>
#include<string.h>
int main()
{
	int caseCount=0,nPeople,nRemain,i,j,card[20],people[50],count,outCount,outList;
	
	while(scanf("%d %d",&nPeople,&nRemain)==2)
	{
		caseCount++;
		memset(people,1,sizeof(people));
		outList=outCount=0;
		for(i=0;i<20;i++)
			scanf("%d",&card[i]);
		for(i=0;i<20;i++)
		{
			count=0;
			for(j=0;j<nPeople;j++)
			{
				if(people[j]==0)
					continue;
				else
				{
					count++;
					if(count==card[i])
					{	
						people[j]=0;
						outList++;
						count=0;
						if(outList==nPeople-nRemain)
							goto door;
					}
				}
			}
		}
door:		printf("Selection #%d\n",caseCount);
		for(i=0;i<nPeople;i++)
		{
			if(people[i]!=0)
			{
				if(outCount==0)
					printf("%d",i+1);
				else
					printf(" %d",i+1);
				outCount++;
			}
			else
				continue;
		}
		printf("\n\n");
	}
	system("pause");
	return 0;
}
