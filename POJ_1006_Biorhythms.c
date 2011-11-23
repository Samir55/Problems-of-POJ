#include<stdio.h>
int main()
{
	int p,e,i,d,j,count=0;
	
	while(1)
	{
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==-1&&e==-1&&i==-1&&d==-1)
			break;
		++count;
		for(j=d+1;j<21252;j++)
			if((j-p)%23==0)
				break;
		for(;j<21252;j=j+23)
			if((j-e)%28==0)
				break;
		for(;j<21252;j=j+23*28)
			if((j-i)%33==0)
				break;
		printf("Case %d: the next triple peak occurs in %d days.\n",count,j-d);
	}
	system("pause");
	return 0;
}
