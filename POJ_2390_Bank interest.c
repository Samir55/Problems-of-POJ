#include<stdio.h>
#include<math.h>
int main()
{
	double interest,sum;
	int year,i;
	
	scanf("%lf %lf %d",&interest,&sum,&year);
	for(i=0;i<year;i++)
		sum=sum*(interest/100+1);
	printf("%ld\n",(long)sum);
	system("pause");
	return 0;
}
