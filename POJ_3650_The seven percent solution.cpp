#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char c;
	
	for(;(c=getchar())!='#';)
	{
		switch(c)
		{
			case ' ':	printf("%%20");break;
			case '!':   printf("%%21");break;
			case '$':   printf("%%24");break;
			case '%':   printf("%%25");break;
			case '(':	printf("%%28");break;
			case ')':	printf("%%29");break;
			case '*':	printf("%%2a");break;
			default :   printf("%c",c);break;
		}
	}
	return 0;
}
