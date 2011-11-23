#include<stdio.h>
#include<string.h>
#define MAXN 300+10
#define NUM 26
char histo[MAXN][NUM]={0};
int analyse[NUM];
int main()
{
	char input[MAXN];
	int i,j,len,max=-1;
	
	memset(histo,' ',sizeof(histo));
	for(i=0;i<4;i++)
	{
		gets(input);
		len=strlen(input);
		for(j=0;j<len;j++)
			if(input[j]>='A' && input[j]<='Z')
				analyse[input[j]-'A']++;
	}
	for(i=0;i<NUM;i++)
	{
		if(max<analyse[i])
			max=analyse[i];
		for(j=MAXN-1;j>MAXN-1-analyse[i];j--)
			histo[j][i]='*';
	}
	for(i=MAXN-max;i<MAXN;i++)
	{
		for(j=0;j<NUM;j++)
		{	
			if(j==0)
				printf("%c",histo[i][j]);
			else
				printf(" %c",histo[i][j]);
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	system("pause");
	return 0;
}
