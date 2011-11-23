#include<stdio.h>
#include<stdlib.h>
int Partition(long *a, int p, int r)
{
	long pivot=a[r],tmp;
	int i=p-1,j=p;
	for(;j<r;j++)
	{
		if(a[j]>=pivot)
		{
			++i;
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
	tmp=a[r];
	a[r]=a[i+1];
	a[i+1]=tmp;
	return (i+1);
}
void Qsort(long *a, int p, int r)
{
	int q;
	if(p<r)
	{
		q=Partition(a,p,r);
		Qsort(a,p,q-1);
		Qsort(a,q+1,r);
	}
}

int main()
{
	int n,i;
	long *weight;
	
	scanf("%d",&n);
	weight=(long *)malloc(sizeof(long)*n);
	for(i=0;i<n;i++)
		scanf("%d",&weight[i]);
	Qsort(weight,0,n-1);
	printf("%ld\n",weight[n/2]);
	system("pause");
	return 0;
}
