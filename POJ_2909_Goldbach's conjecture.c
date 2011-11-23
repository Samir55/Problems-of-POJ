#include<stdio.h>
#include<math.h>
 checkPrim( long num )
{
	long i;
	
	for(i=3;i<=sqrt(num);i++)
		if(num%i==0)
			return 0;
	return 1;
}
int main()
{
	long i,j,num,count;
	
	while(1)
	{
		count=0;
		scanf("%ld",&num);
		if(num==0)
			break;
		for(i=2;i<=num/2;i++)
		{
			if((num-i)%2==0||(i%2==0&&i!=2))
				continue;
			else
			{
				if(checkPrim(i)&&checkPrim(num-i))
					count++;	
			}
		}
		printf("%ld\n",count);
	}
	system("pause");
	return 0;
}
