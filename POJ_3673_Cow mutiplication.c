#include<stdio.h>
#include<string.h>
int main()
{
	char a[15],b[15];
	long i,sum_a=0,sum_b=0,len_a,len_b;
	
	scanf("%s %s",a,b);
	len_a=strlen(a);
	len_b=strlen(b);
	for(i=0;i<len_a;i++)
		sum_a+=(a[i]-'0');
	for(i=0;i<len_b;i++)
		sum_b+=(b[i]-'0');
	printf("%ld\n",sum_a*sum_b);
	system("pause");
	return 0;
}
