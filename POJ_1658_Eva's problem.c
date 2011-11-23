#include<stdio.h>
int main()
{
	int i,n;
	long num[4];
	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3]);
		if((num[1]-num[0]==num[2]-num[1])&&(num[2]-num[1]==num[3]-num[2]))
			printf("%d %d %d %d %d\n",num[0],num[1],num[2],num[3],2*num[3]-num[2]);
		else
			printf("%d %d %d %d %d\n",num[0],num[1],num[2],num[3],num[3]*num[3]/num[2]);
	}
	system("pause");
	return 0;
}
