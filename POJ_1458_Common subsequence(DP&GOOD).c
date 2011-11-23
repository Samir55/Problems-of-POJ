#include<stdio.h>
#include<string.h>
#define MAXN 500
int main()
{
	char str1[MAXN+10],str2[MAXN+10];
	int i,j,maxCS[MAXN+10][MAXN+10],length1,length2;
	
	for(i=0;i<MAXN+5;i++)
		maxCS[i][0]=0;
	for(j=0;j<MAXN+5;j++)
		maxCS[0][j]=0;	
	while(scanf("%s%s",&str1[1],&str2[1])!=EOF)
	{
		length1=strlen(&str1[1]);
		length2=strlen(&str2[1]);
		for(i=1;i<=length1+10;i++)
			for(j=1;j<=length2+10;j++)
			{
				if(str1[i]==str2[j])
					maxCS[i][j]=maxCS[i-1][j-1]+1;
				else
					maxCS[i][j]=maxCS[i-1][j]>maxCS[i][j-1]?maxCS[i-1][j]:maxCS[i][j-1];
			}
		printf("%d\n",maxCS[length1][length2]);
	}
	return 0;
}
