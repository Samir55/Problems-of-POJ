#include<stdio.h>
struct kid
{
	char name[10];
	int size;
}people[9];
int main()
{
	int n,x,y,z,i,max,min;
	
	while (1)
	{
		max=0;
		min=0;
		scanf("%d",&n);
		if(n==-1)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%s",&x,&y,&z,people[i].name);
			people[i].size=x*y*z;
		}
		for(i=0;i<n;i++)
		{
			if(people[i].size>=people[max].size)
				max=i;
			if(people[i].size<=people[min].size)
				min=i;
		}
		printf("%s took clay from %s.\n",people[max].name,people[min].name);
	}
	system("pause");
	return 0;
}
