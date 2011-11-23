#include<stdio.h>
#include<string.h>
int main()
{
	char input[15]={0},spin[15]={0};
	int i,size;
	
	scanf("%s",input);
	size=strlen(input);
	while(scanf("%s",spin)!=EOF)
	{
		for(i=0;i<size;i++)
			input[i]=(input[i]-'0'+spin[i]-'0')%10+'0';
	}
	printf("%s\n",input);
	system("pause");
	return 0;
}
