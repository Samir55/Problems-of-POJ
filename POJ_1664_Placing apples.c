#include<stdio.h>
int main()
{
	int nCases,m,n;
	int place(int,int);
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		scanf("%d %d",&m,&n);
		printf("%d\n",place(m,n));
	}
	system("pause");
	return 0;	
}

int place( int m, int n )
{
	if(m==0||n==1)
		return 1;
	if(n>m)
		return place(m,m);
	return place(m-n,n)+place(m,n-1);
}
