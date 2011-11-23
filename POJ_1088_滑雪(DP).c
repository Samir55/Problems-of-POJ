#include<stdio.h>
#include<string.h>
#define MAXN 200+20
#define INF 20000
int check[MAXN][MAXN];
int map[MAXN][MAXN],opt[MAXN][MAXN];
int main()
{
	int i,j,height,width,longest;
	int search(int, int);
	int max(int, int);

	memset(map,INF,sizeof(map));
	while(scanf("%d%d",&height,&width)!=EOF)
	{
		memset(check,1,sizeof(check));
		memset(opt, 0, sizeof(opt));
		longest=0;
		for(i=1;i<=height;i++)
			for(j=1;j<=width;j++)
				scanf("%d",&map[i][j]);
		for(i=1;i<=height;i++)
			for(j=1;j<=width;j++)
				if(search(i,j)>longest)
					longest=opt[i][j];
		printf("%d\n",longest);
	}
	
	system("pause");
	return 0;
}

int max(int a, int b)
{
	return a>b?a:b;
}

int search(int x, int y)
{
	int tmp_r=1,tmp_l=1,tmp_u=1,tmp_d=1;
	
	if(opt[x][y]!=0)
		return opt[x][y];
	else
	{					
		check[x][y]=0;				
		if(map[x][y+1]<map[x][y]&&check[x][y+1])
			tmp_r=search(x,y+1)+1;
		if(map[x][y-1]<map[x][y]&&check[x][y-1])
			tmp_l=search(x,y-1)+1;
		if(map[x+1][y]<map[x][y]&&check[x+1][y])
			tmp_d=search(x+1,y)+1;
		if(map[x-1][y]<map[x][y]&&check[x-1][y])
			tmp_u=search(x-1,y)+1;
		opt[x][y]=max(max(tmp_u,tmp_d),max(tmp_r,tmp_l));
		check[x][y]=1;
		return opt[x][y];
	}
} 
