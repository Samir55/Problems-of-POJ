#include<stdio.h>
#include<string.h>
#define MAXN 10+5

char one[MAXN]={'-',' ','-','-',' ','-','-','-','-','-'},
	 two[MAXN]={'|',' ',' ',' ','|','|','|',' ','|','|'},
	 three[MAXN]={'|','|','|','|','|',' ',' ','|','|','|'},
	 four[MAXN]={' ',' ','-','-','-','-','-',' ','-','-'},
	 five[MAXN]={'|',' ','|',' ',' ',' ','|',' ','|',' '},
	 six[MAXN]={'|','|',' ','|','|','|','|','|','|','|'},
	 seven[MAXN]={'-',' ','-','-',' ','-','-',' ','-','-'};
	 
int main()
{
	char num[MAXN];
	int i,j,k,size,len;
	
	while(1)
	{
		scanf("%d %s",&size,num);
		if(size==0 && num[0]=='0')
			break;
		len=strlen(num);
		for(i=0;i<len;i++)							
		{
			printf(" ");
			for(j=0;j<size;j++)
				printf("%c",one[num[i]-'0']);
			printf(" ");
			if(i!=len-1)
				printf(" ");
		}
		printf("\n");
		for(k=0;k<size;k++)							
		{
			for(i=0;i<len;i++)
			{
				printf("%c",two[num[i]-'0']);
				for(j=0;j<size;j++)
					printf(" ");
				printf("%c",three[num[i]-'0']);
				if(i!=len-1)
					printf(" ");
			}
			printf("\n");
		}
		for(i=0;i<len;i++)							
		{
			printf(" ");
			for(j=0;j<size;j++)
				printf("%c",four[num[i]-'0']);
			printf(" ");
			if(i!=len-1)
				printf(" ");
		}
		printf("\n");
		for(k=0;k<size;k++)							
		{
			for(i=0;i<len;i++)
			{
				printf("%c",five[num[i]-'0']);
				for(j=0;j<size;j++)
					printf(" ");
				printf("%c",six[num[i]-'0']);
				if(i!=len-1)
					printf(" ");
			}
			printf("\n");
		}
		for(i=0;i<len;i++)						
		{
			printf(" ");
			for(j=0;j<size;j++)
				printf("%c",seven[num[i]-'0']);
			printf(" ");
			if(i!=len-1)
				printf(" ");
		}
		printf("\n\n");
	}
	return 0;
}
