#include<stdio.h>
#include<math.h>

int ori_nume, ori_deno ,nlimit;
long nsol;

int main()
{
	int limit,gcd;
	void DFS(int, int, int, int, int);
	int LCM(int, int);
	int GCD(int, int);
	
	while(1)
	{
		scanf("%d%d%d%d", &ori_nume, &ori_deno, &limit, &nlimit);
		if(ori_nume==0 && ori_deno==0 && limit==0 && nlimit==0)
		    break;;
		gcd=GCD(ori_nume,ori_deno);                     
		nsol=0;
		ori_deno/=gcd;
		ori_nume/=gcd;
		DFS(ori_nume, ori_deno, limit, 1, 1);
		printf("%ld\n",nsol);
	}
	
	return 0;
}

int LCM(int x, int y)
{
	int a=x,b=y,t;
	
	if(x<y)
	{
		x=x+y;
		y=x-y;
		x=x-y;
	}
	while(x%y!=0)
	{
		t=x%y;
		x=y;
		y=t;
	}
	
	return a*b/y;
}

int GCD(int a, int b)
{
	int tmp;

	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}

	if(b%a==0)
		return a;
	else
		return GCD(a,b%a);
}

void DFS(int nume, int deno, int limit, int n, int last)
{
	int i,gcd,up,down;
 	double times;

    if(n==nlimit+1)
	    return;
	if(nume==1 && deno>=last)
	    nsol++;
	for(i=last;i<=sqrt(limit);i++)
	{
		if(nume*i-deno<=0)
		    continue ;
		down=LCM(i,deno);
		times=(double)(i*deno)/(double)down;
		up=(double)(nume*i-deno)/times;
		gcd=GCD(up,down);
		up/=gcd;
		down/=gcd;
		if(i*down>limit)
		   	continue ;
		DFS(up,down,limit/i,n+1,i);
	}
	
	return ;
}
