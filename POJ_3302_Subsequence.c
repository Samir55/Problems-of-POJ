#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXN 100+10
int main()
{
	bool ifsub;
	char str[MAXN],sub[MAXN],rev[MAXN];
	int nCases;
	long len_str,len_sub,len_rev,i,j,k;
	
	scanf("%d",&nCases);
	while(nCases--)
	{	
		scanf("%s %s",str,sub);
		ifsub=true;
		len_str=strlen(str);
		len_sub=strlen(sub);
		i=len_str-1;
		j=len_sub-1;
		if(len_str<len_sub)
			ifsub=false;
		for(k=0;k<=j;k++)
			rev[k]=sub[j-k];
		k=len_sub-1;
		while(ifsub && i>=0)
		{
			if(str[i]==sub[j])
			{
				if(i==0 && j!=0)
				{
					i--;
					ifsub=false;
				}
				if(j==0)
					break;
				else
				{
					i--;
					j--;
				}
			}
			else
			{
				if(i==0)
					ifsub=false;
				else
					i--;
			}
		}
		if(!ifsub)
		{
			ifsub=true;
			i=len_str-1;
			while(ifsub && i>=0)
			{
				if(str[i]==rev[k])
				{
					if(i==0 && k!=0)
					{
						i--;
						ifsub=false;
					}
					if(k==0)
						break;
					else
					{
						i--;
						k--;
					}
				}
				else
				{
					if(i==0)
						ifsub=false;
					else
						i--;
				}
			}
		}
		if(ifsub)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
