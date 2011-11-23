#include<stdio.h>
__int64 result[200][200]={0};
int main()
{
	int m,n,i,j;
	
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(!m&&!n)
			break;
		for(i=0;i<=m-n;i++)
			result[i][1]=1;
		for(j=2;j<=n;j++)
		{
			result[0][j]=1;
			for(i=j;i<=m-n;i++)
			{	
				if(i-j>=j||!(i-j))
					result[i][j]=result[i-j][j]+result[i][j-1];
				else
					result[i][j]=result[i-j][i-j]+result[i][j-1];
				}
		}
		printf("%I64d\n",result[m-n][n]);
	}
	system("pause");
	return 0;
}
