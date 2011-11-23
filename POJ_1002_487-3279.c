#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sort_function(const void *a,const void *b)  
{ 
    return(strcmp((char*)a,(char*)b));  
}   
int main()
{FILE *fin=fopen("zbw1.txt","r");
	char num[50],graph[100001][50],tmp[50];
	int size,count,flag=0;
	long i,j,n,countSame=0;
	memset(graph,0,sizeof(graph));
	memset(tmp,0,sizeof(tmp));
	
	fscanf(stdin,"%ld",&n);
	j=n;
	while(j--)
	{
		memset(num,0,sizeof(num));
		fscanf(stdin,"%s",num);
		size=strlen(num);
		count=0;
		
		for(i=0;i<size;i++)
		{
			if(count==3)
			{
				graph[n-j-1][count]='-';
				count++;
			}
			switch(num[i])
			{
				case 'A':case 'B':case 'C': graph[n-j-1][count]='2';count++;break;
				case 'D':case 'E':case 'F': graph[n-j-1][count]='3';count++;break;
				case 'G':case 'H':case 'I': graph[n-j-1][count]='4';count++;break;
				case 'J':case 'K':case 'L': graph[n-j-1][count]='5';count++;break;
				case 'M':case 'N':case 'O': graph[n-j-1][count]='6';count++;break;
				case 'P':case 'R':case 'S': graph[n-j-1][count]='7';count++;break;
				case 'T':case 'V':case 'U': graph[n-j-1][count]='8';count++;break;
				case 'X':case 'Y':case 'W': graph[n-j-1][count]='9';count++;break;
				case '-':break;
				default :graph[n-j-1][count]=num[i];count++;break;
			}
		}
	}
	qsort((void*)graph, n, sizeof(graph[0]), sort_function);
	for(i=0;i<n;i++)
	{
		if(strcmp(graph[i],tmp)==0)
		{
			countSame++;
			if(i==n-1&&countSame>1)
			{
				printf("%s %ld\n",tmp,countSame);
				flag=1;			
			}
		}
		else
		{
			if(countSame>1)
			{
				printf("%s %ld\n",tmp,countSame);
				flag=1;
			}
			strcpy(tmp,graph[i]);
			countSame=1;
		}
	}
	if(!flag)
		printf("No duplicates.\n");
	system("pause");
	return 0;
}
