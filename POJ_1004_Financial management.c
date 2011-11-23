#include<stdio.h>
int main()
{
	int i;
	float output,amount=0;
	
	for(i=0;i<12;i++)
	{
		scanf("%f",&output);
		amount+=output;
	}
	printf("$%.2f\n",amount/12);
	system("pause");
	return 0;
}
