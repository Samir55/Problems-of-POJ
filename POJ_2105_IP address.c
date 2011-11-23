#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str[35]={0},tmp[9]={0};
	int n,i,j,sum;
	
	scanf("%d",&n);
	while(n--)
	{
		memset(str,0,sizeof(str));
		scanf("%s",str);
		for(i=0;i<32;i++)
		{
			tmp[i%8]=str[i];
			if(tmp[7]!=0)
			{
				sum=0;
				for(j=7;j>=0;j--)
					sum+=(tmp[j]-'0')*pow(2,7-j);
				if(i!=31)
					printf("%d.",sum);
				else
					printf("%d\n",sum);
				memset(tmp,0,sizeof(tmp));
			}
		}
	}
	system("pause");
	return 0;
}
