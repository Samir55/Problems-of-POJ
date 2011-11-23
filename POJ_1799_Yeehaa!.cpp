#include<iostream>
#include<cstdio>
#include<cmath>
#define PI 3.14159265
using namespace std;
int main()
{
	double R;
	int i,j,n,nCases,caseCnt=0;
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		caseCnt++;
		scanf("%lf%d",&R,&n);
		if(n>2)
			printf("Scenario #%d:\n%.3lf\n\n",caseCnt,R/(2*sin(PI*(1.0/2-1.0/n))/sin(2.0*PI/n)+1));
		else
			printf("Scenario #%d:\n%.3lf\n\n",caseCnt,R/2);
	}
	return 0;
}
