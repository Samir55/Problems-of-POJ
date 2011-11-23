#include<iostream>
#include<cstdio>
#include<cmath>
#define PI 3.14159265
using namespace std;
int main()
{
	double D,d,V;
	
	while((cin>>D>>V) && (V || D))
	{
		d=pow(D*D*D-6*V/PI,1.000/3);
		printf("%.3lf\n",d);
	}
	return 0;
}
