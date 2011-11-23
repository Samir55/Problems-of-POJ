#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXN 100000+10
int main()
{
	bool ifsub;
	char a[MAXN],b[MAXN];
	long len_a,len_b,i,j;
	
	while(scanf("%s %s",a,b)!=EOF)
	{
		ifsub=true;
		len_a=strlen(a);
		len_b=strlen(b);
		i=len_a-1;
		j=len_b-1;
		if(len_a>len_b)
			ifsub=false;
		while(ifsub && i>=0)
		{
			if(a[i]==b[j])
			{
				if(i==0)
					i--;
				else
				{
					i--;
					j--;
				}
			}
			else
			{
				if(j==0)
					ifsub=false;
				else
					j--;
			}
		}
		if(ifsub)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
