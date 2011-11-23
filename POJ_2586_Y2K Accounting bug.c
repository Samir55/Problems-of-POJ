#include<stdio.h>
#include<string.h>
int main()
{
	__int64 s,d,sum[4],max;
	int i;
	
	while(scanf("%I64d%I64d",&s,&d)!=EOF)
	{
		max=0;
		memset(sum,0,sizeof(sum));
		if(4*s<d)
			sum[0]=s*10-d*2;
		else if(3*s<2*d)
			sum[1]=8*s-4*d;
		else if(2*s<3*d)
			sum[2]=6*(s-d);
		else if(s<4*d)
			sum[3]=3*s-9*d;
		for(i=0;i<4;i++)
			if(sum[i]>max)
				max=sum[i];
		if(!max)
			printf("Deficit\n");
		else
			printf("%I64d\n",max);
	}
	system("pause");
	return 0;
}
