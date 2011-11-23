#include<stdio.h>
__int64 result[200][200]={0};
int main()
{
	int m,n,i;
	__int64 com(int,int);
	
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(!m&&!n)
			break;
		printf("%I64d\n",com(m-n,n));
	}
	system("pause");
	return 0;
}

__int64 com(int m,int n)
{
	__int64 tmp;
	
	if(result[m][n]!=0)
		return result[m][n];
	else
	{
		if(n==1||m==0)
		{	
			result[m][n]=1;
			return 1;
		}
		if(n>m)
		{	tmp=com(m,m);
			result[m][m]=tmp;
			return tmp;
		}
		tmp=com(m-n,n)+com(m,n-1);
		result[m][n]=tmp;
		return tmp;
	}
}
