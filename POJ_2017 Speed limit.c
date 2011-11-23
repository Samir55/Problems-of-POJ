#include<stdio.h>
int main()
{
	int n,i,sum,v,cur_t,t;
	
	while(1)
	{	
		scanf("%d",&n);
		if(n==-1)
			break;
			sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&v,&cur_t);
			if(i==0)
				sum+=v*cur_t;
			else
				sum+=v*(cur_t-t);
			t=cur_t;
		}
		printf("%d miles\n",sum);
	}
	system("pause");
	return 0;
}
