#include<stdio.h>
int main()
{
	int h,s,i,j,k,sum,map[20][20],count;
	
	while(scanf("%d%d",&h,&s)!=EOF)
	{
		j=k=0;
		memset(map,0,sizeof(map));
		sum=h*(h+1)/2;
		for(i=s,count=1;count<=sum;i++,count++)
		{
			map[j++][k]=i;
			if(j*(j+1)/2==count)
			{
				j=0;
				k++;	
			}
			if(i==9)
				i=0;
		}
		for(i=0;i<h;i++)
			for(j=0;j<h;j++)
			{
				if(j<i)
				{
					if(j==0)
						printf(" ");
					else
						printf("  ");
				}
				else
				{
					if(i==0&&j==0)
						printf("%d",map[0][0]);
					else
						printf(" %d",map[i][j]);
				}			
				if(j==h-1)
					printf("\n");
			}
	}
	system("pause");
	return 0;
}
