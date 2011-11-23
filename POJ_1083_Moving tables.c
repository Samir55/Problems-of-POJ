#include<stdio.h>
#include<string.h>
int  corridor[201]={0};
int main()
{
	int T,n,i,j,start,end,tmp,max,time;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(corridor,0,sizeof(corridor));
		max=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&start,&end);
			if(end<start)
			{
				tmp=end;
				end=start;
				start=tmp;
			}
			for(j=(start+1)/2;j<=(end+1)/2;j++)
				corridor[j]++;
		}
		for(i=0;i<201;i++)
			if(corridor[i]>max)
				max=corridor[i];
		printf("%d\n",max*10);
	}
	system("pause");
	return 0;
}
