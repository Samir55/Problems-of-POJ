#include<stdio.h>
#include<string.h>
int Partition( int *a , int p , int r )
{
	int i=p-1,j=p,pivot=a[r],tmp;
	
	for(;j<r;j++)
	{
		if(a[j]>=pivot)
		{
			++i;
			tmp=a[j];
			a[j]=a[i];
			a[i]=tmp;
		}
	}
	tmp=a[r];
	a[r]=a[i+1];
	a[i+1]=tmp;
	return i+1;
}
void Qsort( int *a , int p , int r )
{
	int q;
	
	if(p<r)
	{
		q=Partition(a,p,r);
		Qsort(a,p,q-1);
		Qsort(a,q+1,r);
	}
	return ;
}
int main()
{
	int n,friends,i,count=0,countFriends,flag,stampsOwn[1000];
	long stampsNeed,sum;
	
	scanf("%d",&n);
	while(n--)
	{
		count++;
		sum=0;
		countFriends=0;
		flag=0;
		memset(stampsOwn,0,sizeof(stampsOwn));
		
		scanf("%ld %d",&stampsNeed,&friends);
		for(i=0;i<friends;i++)
			scanf("%d",&stampsOwn[i]);
		Qsort(stampsOwn,0,friends-1);
		for(i=0;i<friends;i++)
		{
			sum+=stampsOwn[i];
			countFriends++;
			if(sum>=stampsNeed)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			printf("Scenario #%d:\n%d\n\n",count,countFriends);
		}
		else
			printf("Scenario #%d:\nimpossible\n\n",count);
	}
	system("pause");
	return 0;
}
