#include<stdio.h>
int main()
{
	int n,i,j,map[100][100],sum_l,sum_c,count_l,count_c,tmp_l,tmp_c;
	
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		memset(map,0,sizeof(map));
		count_l=count_c=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&map[i][j]);
		for(i=0;i<n;i++)
		{
			sum_l=0;
			for(j=0;j<n;j++)
			{
				sum_l+=map[i][j];
				if(j==n-1)
				{
					if(sum_l%2!=0)
					{
						tmp_l=i;
						count_l++;
					}
					else
						continue;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			sum_c=0;
			for(i=0;i<n;i++)
			{
				sum_c+=map[i][j];
				if(i==n-1)
				{
					if(sum_c%2!=0)
					{
						tmp_c=j;
						count_c++;
					}
					else
						continue;
				}
			}
		}
		if(count_c==0&&count_l==0)
			printf("OK\n");
		else
		{
			if(count_c>1||count_l>1)
				printf("Corrupt\n");
			else
				printf("Change bit (%d,%d)\n",tmp_l+1,tmp_c+1);
		}
	}
	system("pause");
	return 0;
}