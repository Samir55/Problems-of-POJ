#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 1000000+20
using namespace std;
char str[MAXN],tmp[MAXN],sub[MAXN];
int main()
{
	int len,j,cnt;

	while(scanf("%s",str) && (str[0]!='.'))
	{
		j=cnt=1;
		memset(tmp,0,sizeof(tmp));
		memset(sub,0,sizeof(sub));
		len=strlen(str);
		strncpy(tmp,str,1);
		while(1)
		{
			strncpy(sub,str+j,strlen(tmp));
			if(strcmp(sub,tmp)==0)
			{
				j+=strlen(tmp);
				cnt++;
				if(j==len)
					break;
				else if(j>len)
				{
					cnt=1;
					break;
				}
			}
			else
			{
				j+=strlen(tmp);
				strncpy(tmp,str,(cnt+1)*strlen(tmp));
				cnt=1;
				if(j>(len+1)/2)
					break;
			}
		}
		printf( "%d\n", cnt );
	}
	return 0;
}
