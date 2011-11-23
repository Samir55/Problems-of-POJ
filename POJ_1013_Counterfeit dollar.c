#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{	
	char left[3][20],right[3][20],result[3][10];
	int n,i,j,coin[15],max,min,count1,count2;
	FILE *fin=fopen("zbw.txt","r");
	
	fscanf(fin,"%d",&n);
	while(n--)
	{
		memset(coin,0,sizeof(coin));
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(result,0,sizeof(result));
		max=min=0;
		
		for(i=0;i<3;i++)
			fscanf(fin,"%s %s %s",left[i],right[i],result[i]);
		for(i=0;i<3;i++)
		{
			if(strcmp(result[i],"even")==0)
			{
				for(j=0;left[i][j]-65>=0;j++)
					coin[left[i][j]-65]=1;
				for(j=0;right[i][j]-65>=0;j++)
					coin[right[i][j]-65]=1;
			}
			if(strcmp(result[i],"down")==0)
			{
				for(j=0;left[i][j]-65>=0;j++)
					if(coin[left[i][j]-65]!=1)
						coin[left[i][j]-65]-=2;
				for(j=0;right[i][j]-65>=0;j++)
					if(coin[right[i][j]-65]!=1)
						coin[right[i][j]-65]+=2;
			}
			if(strcmp(result[i],"up")==0)
			{
				for(j=0;left[i][j]-65>=0;j++)
					if(coin[left[i][j]-65]!=1)
						coin[left[i][j]-65]+=2;
				for(j=0;right[i][j]-65>=0;j++)
					if(coin[right[i][j]-65]!=1)
						coin[right[i][j]-65]-=2;
			}
		}
		for(i=0;i<14;i++)
			if(coin[i]>coin[max]&&coin[i]!=1)
				max=i;
		for(i=0;i<13;i++)
			if(coin[i]<coin[min]&&coin[i]!=1)
				min=i;  
		if(abs(coin[max])>abs(coin[min]))
			printf("%c is the counterfeit coin and it is heavy.\n",max+65);
		if(abs(coin[min]-1)>abs(coin[max]-1))
			printf("%c is the counterfeit coin and it is light.\n",min+65);
	}
	system("pause");
	return 0;
}
