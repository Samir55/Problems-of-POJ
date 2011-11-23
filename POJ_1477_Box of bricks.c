#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*bricks,i,sum,ave,times,count=0;
	
	while(1)
	{
		count++;
		scanf("%d",&n);
		if(!n)
			break;
		else
		{
			times=ave=sum=0;
			bricks=(int *)malloc(sizeof(int)*n);
			
			for(i=0;i<n;i++)
			{
				scanf("%d",&bricks[i]);
				sum+=bricks[i];
			}
			ave=sum/n;
			for(i=0;i<n;i++)
				times+=abs(ave-bricks[i]);
			printf("Set #%d\nThe minimum number of moves is %d.\n\n",count,times/2);
		}
		free(bricks);
	}
	system("pause");
	return 0;
}
