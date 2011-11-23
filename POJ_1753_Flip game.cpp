#include<iostream>
#include<cstring>
#define MAXN 6
#define INF 100000
using namespace std;

char input[MAXN][MAXN]={0};
int map[MAXN][MAXN]={0},flip_b[MAXN][MAXN],flip_w[MAXN][MAXN];
int b_step,w_step,ans=INF;

int main()
{
	int i,j;
	void search();
	
	for(i=1;i<5;i++)
		cin>>&input[i][1];
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
		{
			if(input[i][j]=='b')
				map[i][j]=1;
			else
				map[i][j]=0;
		}
	search();
	if(ans==INF)
		cout<<"Impossible"<<endl;
	else
		cout<<ans<<endl;
	system("pause");
	return 0;
}

void search()
{
	int i,j,k,l,m,n;
	
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
				for(l=0;l<2;l++)
				{
					b_step=w_step=0;
					memset(flip_b,0,sizeof(flip_b));
					memset(flip_w,0,sizeof(flip_w));
					flip_b[1][1]=flip_w[1][1]=i;flip_b[1][2]=flip_w[1][2]=j;
					flip_b[1][3]=flip_w[1][3]=k;flip_b[1][4]=flip_w[1][4]=l;
					
					for(m=2;m<5;m++)
						for(n=1;n<5;n++)
						{
							if((map[m-1][n]+flip_b[m-1][n]+flip_b[m-1][n-1] 
							    +flip_b[m-1][n+1]+flip_b[m-2][n])%2==0)
							{
								flip_b[m][n]=1;
								b_step++;
							}
							if((map[m-1][n]+flip_w[m-1][n]+flip_w[m-1][n-1] 
							    +flip_w[m-1][n+1]+flip_w[m-2][n])%2==1)
							{
								flip_w[m][n]=1;
								w_step++;
							}    
						}
					for(m=1;m<5;m++)
						if((map[4][m]+flip_b[4][m-1]+flip_b[4][m]+flip_b[4][m+1]
						   +flip_b[3][m])%2==0)
						   break;
					for(n=1;n<5;n++)
						if((map[4][n]+flip_w[4][n-1]+flip_w[4][n]+flip_w[4][n+1]
						   +flip_w[3][n])%2==1)
						   break;
					if(m==5 && b_step+i+j+k+l<ans)
						ans=b_step+i+j+k+l;
					if(n==5 && w_step+i+j+k+l<ans)
						ans=w_step+i+j+k+l;
				}
	return ;
}
