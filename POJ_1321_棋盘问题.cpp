#include<iostream>
#define MAXN 10
using namespace std;

char checker[MAXN][MAXN];
int n,k,row[MAXN],col[MAXN],placed;
long sol;

int main()
{
	int i,j;
	void dfs(int, int);
	
	while(1)
	{
		for(i=0;i<MAXN;i++)
			row[i]=col[i]=1;
		sol=0;
		cin>>n>>k;
		if(n==-1 && k==-1)	
			break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>checker[i][j];
		for(j=0;j<n;j++)
			for(i=0;i<n;i++)
				if(checker[i][j]=='#')
				{	
					placed=1;
					if(k==1)
					{
						sol++;
						placed--;
						continue;
					}
					dfs(i,j);
					placed=0;
				}
		cout<<sol<<endl;
	}
	return 0;
}

void dfs(int x, int y)
{
	int i,j;
	
	row[x]=0;
	col[y]=0;
	for(j=y+1;j<n;j++)
		for(i=0;i<n;i++)
			if(row[i] && col[j] && checker[i][j]=='#')
			{	
				placed++;
				if(placed==k)
				{
					sol++;
					placed--;
					continue;
				}
				dfs(i,j);
				placed--;
			}
	row[x]=1;
	col[y]=1;
	return ;		
}
