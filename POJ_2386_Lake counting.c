#include<stdio.h>
#include<string.h>
char map[105][105];
int main()
{
	int m,n,i,j,count=0;
	void search(int,int);
	memset(map,'.',sizeof(map));

	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%s",&map[i][1]);
	for(i=1;i<=m;i++)
		map[i][n+1]='.';
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(map[i][j]=='W')
			{
				search(i,j);
				count++;
			}
			else
				continue;
		}
	printf("%d\n",count);
	return 0;
}

void search(int i,int j)
{
	if(map[i][j]=='.'||map[i][j]=='x')
		return ;
	else
	{
		map[i][j]='x';
		search(i-1,j-1);
		search(i-1,j);
		search(i-1,j+1);
		search(i,j+1);
		search(i,j-1);
		search(i+1,j-1);
		search(i+1,j);
		search(i+1,j+1);
		return ;
	}
}
