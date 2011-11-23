#include<stdio.h>
#include<string.h>
int main()
{	
	char forStack[100][80],backStack[100][80],URL[80]="http://www.acm.org/",oprt[10];
	int forTop=-1,backTop=-1;
	
	while(1)
	{
		fscanf(stdin,"%s",oprt);
		if(strcmp(oprt,"VISIT")==0)
		{
			strcpy(backStack[++backTop],URL);
			forTop=-1;
			fscanf(stdin,"%s",URL);
			printf("%s\n",URL);
		}
		if(strcmp(oprt,"BACK")==0)
		{
			if(backTop>=0)
			{
				strcpy(forStack[++forTop],URL);
				strcpy(URL,backStack[backTop--]);
				printf("%s\n",URL);
			}
			else
				printf("Ignored\n");
		}
		if(strcmp(oprt,"FORWARD")==0)
		{
			if(forTop>=0)
			{
				strcpy(backStack[++backTop],URL);
				strcpy(URL,forStack[forTop--]);
				printf("%s\n",URL);
			}
			else 
				printf("Ignored\n");
		}
		if(strcmp(oprt,"QUIT")==0)
			break;
	}
	return 0;
}
