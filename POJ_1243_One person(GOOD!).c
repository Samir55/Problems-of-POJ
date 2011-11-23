#include<stdio.h>
int check( int g, int l)
{
	int i,n=1;
	if(g==0)
		return 0;
	if(l==0)
		return g;
	if(g<=l)
	{
		for(i=0;i<g;i++)
			n*=2;
		return n-1;
	}
	else
		return (check(g-1,l-1)+check(g-1,l)+1);
	
}
int main()
{
	int g,l,count=0;;
	
	
	while(1)
	{
		scanf("%d%d",&g,&l);
		if(g==0&&l==0)
			break;
		++count;
		printf("Case %d: %d\n",count,check(g,l));
	}
	system("pause");
	return 0;
}
