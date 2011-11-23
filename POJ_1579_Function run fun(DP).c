#include<stdio.h>
int main()
{
	long num[30][30][30];
	int i,j,k,a,b,c;
	
	while(1)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1)
			break;
		memset(num,0,sizeof(num));
		for(i=0;i<21;i++)
			for(j=0;j<21;j++)
				for(k=0;k<21;k++)
				{
					if(i * j * k==0)
						num[i][j][k]=1;
					else if(a<b&&b<c)
						num[i][j][k] = num[i][j][k-1] + num[i][j-1][k-1] - num[i][j-1][c]; 
					else
						num[i][j][k] = num[i-1][j][k] + num[i-1][j-1][k] + num[i-1][j][k-1] 
									   - num[i-1][j-1][k-1]; 
				}
		if( a<=0 || b<=0 || c<=0 )
			printf("w(%d, %d, %d) = 1\n",a,b,c);
		else if( a>20 || b>20 || c>20 )
			printf("w(%d, %d, %d) = %ld\n",a,b,c,num[20][20][20]);
		else
			printf("w(%d, %d, %d) = %ld\n",a,b,c,num[a][b][c]);
	}
	system("pause");
	return 0;
}
