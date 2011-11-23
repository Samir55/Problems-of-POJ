#include<stdio.h>
#include<string.h>
int main()
{
	char str[256]={0};
	int i,size;
	long sum;
	
	while(1)
	{
		sum=0;
		gets(str);
		if(str[0]=='#')
			break;
		size=strlen(str);
		for(i=0;i<size;i++)
		{
			if(str[i]==' ')
				continue;
			sum+=(str[i]-64)*(i+1);
		}
		printf("%ld\n",sum);
	}
	system("pause");
	return 0;
}
