#include<stdio.h>
int main()
{
	int map[10050]={0},i;
	
	for(i=1;i<=10000;i++)
	{
		map[i+i/10000+i%10000/1000+i%1000/100+i%100/10+i%10]=1;
	}
	for(i=1;i<=10000;i++)
		if(!map[i])
			printf("%d\n",i);
	system("pause");
	return 0;
}
