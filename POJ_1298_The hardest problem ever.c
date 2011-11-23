#include<stdio.h>
#include<string.h>
#define MAXN 100*40+10
int main()
{
	char input[MAXN],output[MAXN];
	int i,len;
	
	while(1)
	{
		gets(input);
		if(strcmp(input,"ENDOFINPUT")==0)
			break;
		while(strcmp(input,"START")==0)
		{
			gets(input);
			len=strlen(input);
			for(i=0;i<len;i++)
			{
				if(input[i]>='A'&&input[i]<='Z')
					output[i]=(input[i]-'A'+21)%26+'A';
				else
					output[i]=input[i];
			}
			gets(input);
		}
		for(i=0;i<len;i++)
			printf("%c",output[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}
