#include<stdio.h>
#define PI 3.1415927
int main()
{
	int count=0,n;
	long i=1,area=0;
	float x,y,size;
		
	scanf("%d",&n);
	while(n--)
	{
		area=0;
		count++;
		scanf("%f %f",&x,&y);
		size=PI*(x*x+y*y)/2;
		for(i=1;;i++)
		{
			area+=50;
			if(area>size)
				break;
		}
		printf("Property %d: This property will begin eroding in year %ld.\n",count,i);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
