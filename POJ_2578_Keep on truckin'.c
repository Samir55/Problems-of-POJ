#include<stdio.h>

int main()
{
	int a,b,c,i;
	
	scanf("%d%d%d",&a,&b,&c);
	if(a<=168)
	{
		printf("CRASH %d\n",a);system("pause");
		return 0;
	}
	if(b<=168)
	{
		printf("CRASH %d\n",b);system("pause");
		return 0;
	}
	if(c<=168)
	{
		printf("CRASH %d\n",c);system("pause");
		return 0;
	}
	printf("NO CRASH\n");
	
	system("pause");
	return 0;
}
