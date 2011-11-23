#include<stdio.h>
int main()
{
	int n,hour,min,times[25]={12,13,14,15,16,17,18,19,20,21,22,23,24,1,2,3,4,5,6,7,8,9,10,11};
	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d:%d",&hour,&min);
		if(min==0)
			printf("%d\n",times[hour]);
		else
			printf("0\n");
	}
	system("pause");
	return 0;
}
