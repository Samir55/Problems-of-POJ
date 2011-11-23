#include<stdio.h>
#include<string.h>
#define MAXN 400+10
int opt[MAXN][MAXN];
int main()
{
	char str_A[MAXN],str_B[MAXN],str_C[MAXN*2];
	int i,j,k,nCases,caseCount=0,len_A,len_B;
	
	scanf("%d",&nCases);		
	opt[0][0]=1;
	while(nCases--)
	{
		memset(opt,0,sizeof(opt));
		opt[0][0]=1;
		k=1;
		caseCount++;
		scanf("%s %s %s",&str_A[1],&str_B[1],&str_C[1]);
		len_A=strlen(str_A+1);
		len_B=strlen(str_B+1);
		for(i=0;i<=len_A;i++)
			for(j=0;j<=len_B;j++)
			{
				if(opt[i][j])
				{
					k=opt[i][j];
					if(str_A[i+1]==str_C[k])
						opt[i+1][j]=k+1;
					if(str_B[j+1]==str_C[k])
						opt[i][j+1]=k+1;
					k++;
				}
			}
		if(opt[len_A][len_B])
			printf("Data set %d: yes\n",caseCount);
		else
			printf("Data set %d: no\n",caseCount);
	}
	return 0;
}
