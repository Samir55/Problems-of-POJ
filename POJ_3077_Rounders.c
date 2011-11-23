#include <stdio.h>
int main()
{   
	int i,N,x,k;
	long a;
	
    scanf("%d",&N);
   	while (N--)
	{ 
		k=0;
		scanf("%d",&a);
	  	while (a>10)
		{
			x=a%10; 
		  	a/=10;
		  	k++;
		  	if (x>=5)
			   a=a+1;
		}
	    printf ("%d",a);
	    for (i=0;i<k;i++)
			printf("0");
	    printf("\n");
	}
	system("pause");
	return 0;
}
