#include<stdio.h>
int main()
{
	int n,sum,abso;
	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&sum,&abso);
		if(sum-abso<0||(sum+abso)%2!=0)
			printf("impossible\n");
		else
			printf("%d %d\n",(sum+abso)/2,(sum-abso)/2);	
	}
	system("pause");
	return 0;
}
