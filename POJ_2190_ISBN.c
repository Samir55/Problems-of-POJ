#include<stdio.h>
#include<string.h>
int main()
{
	char ISBN[15]={0},digit;
	int i,j,sum=0,loc,flag=0;
	
	scanf("%s",ISBN);
	for(i=0;i<9;i++)
	{
		if(ISBN[i]=='?')
		{
			loc=i;
			continue;
		}
		sum+=(10-i)*(ISBN[i]-'0');
	}
	if(ISBN[9]=='X')
		sum+=10;
	else if(ISBN[9]=='?')
		loc=9;
	else 
		sum+=ISBN[9]-'0';
	for(i=0;i<10;i++)
		if((sum+i*(10-loc))%11==0)
		{
			flag=1;
			digit=i+'0';
			break;
		}
	if(loc==9&&!flag)
		if((sum+10)%11==0)
			flag=2;
	if(flag==1)
		printf("%c\n",digit);
	else if(flag==2)
		printf("X\n");
	else
		printf("-1\n");
	system("pause");
	return 0;
}
