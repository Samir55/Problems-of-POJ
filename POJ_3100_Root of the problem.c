#include<stdio.h>
#include<math.h>
int main()
{
	long b,i,c,tmp,difference1,difference2;
	int n;
	
	while(1)
	{
		scanf("%ld %d",&b,&n);
		tmp=0;
		if(b==0&&n==0)
			break;
		for(i=1;;i++)
		{
			c=pow(i,n);
			difference1=abs(b-tmp);
			difference2=abs(b-c);
			if(difference2>=difference1)
			{
				printf("%ld\n",i-1);
				break;
			}
			tmp=c;
		}
	}
	system("pause");
	return 0;
}
