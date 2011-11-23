#include<stdio.h>
int main()
{
	float length,sum;
	int i;
	
	while(1)
	{
		sum=0;
		scanf("%f",&length);
		if(!length)
			break;
		for(i=2;;i++)
		{
			sum+=(1/(float)i);
			if(sum>=length)
			{
				printf("%d card(s)\n",i-1);
				break;
			}
		}
	}
	system("pause");
	return 0;
}




