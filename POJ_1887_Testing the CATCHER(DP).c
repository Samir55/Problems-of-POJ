#include<stdio.h>
#include<string.h>
#define MAXN 8000+20
int height[MAXN],opt[MAXN];
int main()
{
	int i,j,caseCounter=0,input,dataCounter,ifTerminate,longest;
	
	while(1)
	{
		caseCounter++;
		ifTerminate=dataCounter=0;
		memset(height,0,sizeof(height));
		memset(opt,0,sizeof(opt));
		while(1)
		{
			scanf("%d",&input);
			if(dataCounter==0&&input==-1)
			{	
				ifTerminate=1;
				break;
			}
			else if(input==-1)
				break;
			else
				height[dataCounter++]=input;
		}
		if(ifTerminate)
			break;
		else
		{
			for(i=0;i<dataCounter;i++)
			{
				longest=0;
				for(j=0;j<i;j++)
					if(height[j]>height[i] && opt[j]>longest)
						longest=opt[j];
				opt[i]=longest+1;
			}
		}
		for(i=0;i<dataCounter;i++)
			if(opt[i]>longest)
				longest=opt[i];
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",caseCounter,longest);
	}
	system("pause");
	return 0;
}
