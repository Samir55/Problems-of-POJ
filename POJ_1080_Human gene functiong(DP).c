#include<stdio.h>
#include<string.h>
#define MAXN 100+10
int	table[MAXN][MAXN],opt[MAXN][MAXN]={0};
int main()
{
	char DNA_a[MAXN],DNA_b[MAXN];
	int i,j,len_a,len_b,nCases;
	table['A']['A']=table['C']['C']=table['G']['G']=table['T']['T']=5;
	table['A']['C']=table['C']['A']=-1;table['A']['G']=table['G']['A']=-2;
	table['A']['T']=table['T']['A']=-1;table['A']['-']=table['-']['A']=-3;
	table['C']['G']=table['G']['C']=-3;table['C']['T']=table['T']['C']=-2;
	table['C']['-']=table['-']['C']=-4;table['G']['T']=table['T']['G']=-2;
	table['G']['-']=table['-']['G']=-2;table['T']['-']=table['-']['T']=-1;
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		scanf("%d %s",&len_a,&DNA_a[1]);
		scanf("%d %s",&len_b,&DNA_b[1]);
		for(i=1;i<=len_a;i++)
			opt[i][0]=opt[i-1][0]+table[DNA_a[i]]['-'];
		for(j=1;j<=len_b;j++)
			opt[0][j]=opt[0][j-1]+table['-'][DNA_b[j]];
		for(i=1;i<=len_a;i++)
		{
			for(j=1;j<=len_b;j++)
			{
				opt[i][j]=opt[i-1][j-1]+table[DNA_a[i]][DNA_b[j]];
				if(opt[i][j]<opt[i-1][j]+table[DNA_a[i]]['-'])
					opt[i][j]=opt[i-1][j]+table[DNA_a[i]]['-'];
				if(opt[i][j]<opt[i][j-1]+table['-'][DNA_b[j]])
					opt[i][j]=opt[i][j-1]+table['-'][DNA_b[j]];
			}
		}
		printf("%d\n",opt[len_a][len_b]);
	}
	return 0;
}
