#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char oprt;
	int N,K,Pi,*real,*suspect,*trial,side,i,max,min,countMax=0,countMin=0,countReal=0;

	scanf("%d %d",&N,&K);
	real=(int *)malloc(sizeof(int)*(N+1));
	suspect=(int *)malloc(sizeof(int)*(N+1));
	for(i=0;i<N+1;i++)
		suspect[i]=real[i]=0;
	while(K--)
	{
		scanf("%d",&side);
		trial=(int *)malloc(sizeof(int)*2*side);
		for(i=0;i<2*side;i++)
			scanf("%d",&trial[i]);
		getchar();
		scanf("%c",&oprt);
		if(oprt=='=')
		{
			for(i=0;i<2*side;i++)
				real[trial[i]]=1;
		}
		else if (oprt=='<')
		{
			for(i=0;i<2*side;i++)
			{
				if(i<=side-1)
					suspect[trial[i]]--;
				else
					suspect[trial[i]]++;
			}
		}
		else
		{
			for(i=0;i<2*side;i++)
			{
				if(i<=side-1)
					suspect[trial[i]]++;
				else
					suspect[trial[i]]--;
			}
		}
	}
	for(i=1;i<N+1;i++)
		if(!real[i])
		{
			max=min=i;
			countReal++;
		}
	if(countReal==1)
	{
		printf("%d\n",max);
		system("pause");
		return;
	}
	for(i=1;i<N+1;i++)		
	{
		if(real[i])
			continue;
		if(suspect[i]>suspect[max])
			max=i;
		if(suspect[i]<suspect[min])
			min=i;
	}
	for(i=1;i<N+1;i++)
	{
		if(real[i])
			continue;
		if(suspect[i]==suspect[max])
			countMax++;
		if(suspect[i]==suspect[min])
			countMin++;
	}
	if(abs(suspect[max])>abs(suspect[min])&&countMax==1)
		printf("%d\n",max);
	else if(abs(suspect[max])<abs(suspect[min])&&countMin==1)
		printf("%d\n",min);
	else 
		printf("0\n");
	system("pause");
	return 0;
}
