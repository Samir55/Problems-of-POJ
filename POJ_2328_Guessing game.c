#include<stdio.h>
#include<string.h>
#define N 250
int main(void)
{	
	char c[10];
	int i,j,l=0,h=0,guess,low[N]={0},high[N]={10},count_l=0,count_h=0;

	scanf("%d",&guess);
	getchar();
	while(guess!=0)
	{
		gets(c);
		if(strcmp(c,"too low")==0)
		{
			l++;
			low[l-1]=guess;
		}
		else if(strcmp(c,"too high")==0)
		{
			h++;
			high[h-1]=guess;
		}
		else if(strcmp(c,"right on")==0)
		{
			for(i=0;i<h;i++)
			{
				if(guess<high[i])
					count_h++;	
			}
			for(j=0;j<l;j++)
			{
				if(guess>low[j])
					count_l++;
			}
			if(count_h==h&&count_l==l)
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			l=0;count_l=0;count_h=0;h=0;
		}
		scanf("%d",&guess);
		getchar();
	}
		system("pause");
	    return 0;
}
