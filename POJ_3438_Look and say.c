#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,length,count=0;
	char arr[1001]={0},tmp;
	
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",arr);
		tmp=arr[0];
		length=strlen(arr);
		arr[length+1]='?';
		count=0;
		for(i=0;i<length+1;i++)
		{
			if(arr[i]!=tmp)
			{
				printf("%d%c",count,tmp);
				count=1;
				tmp=arr[i];
			}
			else
				count++;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
