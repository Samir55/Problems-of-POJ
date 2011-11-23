#include<stdio.h>
int main()
{
	char ans[5],guess[5];
	int nCases,count_a,count_b,i,j;
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		count_a=count_b=0;
		scanf("%s %s",ans,guess);
		for(i=0;i<4;i++)
			if(ans[i]==guess[i])
			{
				count_a++;
				ans[i]=guess[i]='X';
			}
		for(i=0;i<4;i++)
		{
			if(ans[i]=='X')
				continue;
			for(j=0;j<4;j++)
			{
				if(guess[j]=='X')
					continue;
				if(guess[j]==ans[i])
					count_b++;
			}
		}
		printf("%dA%dB\n",count_a,count_b);
	}
	system("pause");
	return 0;
}
