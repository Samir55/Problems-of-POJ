#include<stdio.h>
#define MAXN 5000
char str[MAXN+10],rev_str[MAXN+10];
short opt[2][MAXN+10]={0};
int main()
{
	int i,j,len;
	
	while(scanf("%d",&len)!=EOF)
	{
		scanf("%s",&str[1]);
		memset(opt,0,sizeof(opt));
		for(i=1;i<=len;i++)
			rev_str[i]=str[len-i+1];
		rev_str[i]='\0';
		for(i=1;i<=len;i++)
			for(j=1;j<=len;j++)
			{
				if(str[i]==rev_str[j])
					opt[i%2][j]=opt[(i-1)%2][j-1]+1;	
				else
					opt[i%2][j]=opt[(i-1)%2][j]>opt[i%2][j-1]?opt[(i-1)%2][j]:opt[i%2][j-1];
			}//太精彩了！！！滚动数组！！！！！！！ 
		printf("%d\n",len-opt[len%2][len]);
	}
	system("pause");
	return 0;
}
