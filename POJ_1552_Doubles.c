#include<stdio.h>
#include<string.h>
int compare( const void *p1, const void *p2)
{
	const int *a1=(const int *)p1;
	const int *a2=(const int *)p2;
	
	if(*a1<*a2)
		return -1;
	else if(*a1==*a2)
		return 0;
	else 
		return 1;
}
int main()
{
	int i,j,k,num[20],count;
	
	while(1)
	{
		memset(num,0,sizeof(num));
		count=0;
		
		for(i=0;;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]==0)
				break;
			else if(num[i]==-1)
				return 0;
		}
		qsort((void *)num,i,sizeof(int),compare);
		for(j=0;j<i;j++)
			for(k=j;k<i;k++)
				if(num[k]==2*num[j])
					count++;
		printf("%d\n",count);
	}
}
