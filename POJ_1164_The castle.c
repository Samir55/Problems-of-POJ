#include<stdio.h>
int map[55][55]={0},check[55][55]={0},count=0,size=0,m,n;
int main()
{
	void search(int,int);
	int i,j;
	long max=0;
	
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(check[i][j]>0)
				continue;
			else
			{
				size=0;
				count++;
				search(i,j);
				if(size>max)
					max=size;
			}
		}
	}
	printf("%d\n%ld\n",count,max);
	system("pause");
	return 0;
}

void search( int x , int y )
{	
	size++;
	check[x][y]=count;
	if(y>0&&map[x][y]%2==0)
		if(check[x][y-1]==0)
			search(x,y-1);
	if(x+1<=m-1&&map[x][y]<8)
		if(check[x+1][y]==0)
			search(x+1,y);
	if(y+1<=n-1&&map[x][y]!=4&&map[x][y]!=5&&map[x][y]!=6&&map[x][y]!=7&&map[x][y]!=12&&map[x][y]!=13&&map[x][y]!=14&&map[x][y]!=15)
		if(check[x][y+1]==0)
			search(x,y+1);
	if(x>0&&map[x][y]!=2&&map[x][y]!=3&&map[x][y]!=6&&map[x][y]!=7&&map[x][y]!=10&&map[x][y]!=11&&map[x][y]!=14&&map[x][y]!=15)
		if(check[x-1][y]==0)	
			search(x-1,y);
	return ;
}
