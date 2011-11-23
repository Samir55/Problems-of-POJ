#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,num[3010],*p,i,j,flag=0;
	
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		p=(int *)malloc(sizeof(int)*n);
		memset(num,0,sizeof(num));
		
		for(i=0;i<n;i++)
			scanf("%d",&p[i]);
		if(n==1)
			printf("Jolly\n");
		else
		{		
			for(i=0;i<n-1;i++)
			{
				num[abs(p[i+1]-p[i])]=1;
			}
			for(i=1;i<n;i++)
				if(!num[i])
					flag=1;
			if(flag)
				printf("Not jolly\n");
			else
				printf("Jolly\n");
		}
	}
	system("pause");
	return 0;
}
