#include<stdio.h>
int main()
{
	int count=0,n,esp=0;
	
	scanf("%d",&count);
	while(count--)
	{
		esp=0;
		scanf("%d",&n);
		if(n>=1)	esp++;
		if(n>=4)	esp++;
		if(n>=9)	esp++;
		if(n>=16)	esp++;
		if(n>=25)	esp++;
		if(n>=36)	esp++;
		if(n>=49) 	esp++;
		if(n>=64)	esp++;
		if(n>=81)	esp++;
		if(n>=100)	esp++;
		printf("%d\n",esp);
	}
	system("pause");
	return 0;
}
