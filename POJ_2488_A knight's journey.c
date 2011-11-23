#include<stdio.h>
#include<string.h>
#define MAXN 20+7
char place[MAXN*MAXN];
int map[MAXN][MAXN],ifFound,height,width,step;
int main()
{
	int i,j,nCases,casesCounter=0;
	void dfs(int, int);
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		memset(map,0,sizeof(map));
		memset(place,0,sizeof(place));
		ifFound=0;
		casesCounter++;
		scanf("%d%d",&height,&width);
		step=0;
		dfs(0,0);
		if(ifFound)	
			printf("Scenario #%d:\n%s\n\n",casesCounter,place);
		else
			printf("Scenario #%d:\nimpossible\n\n",casesCounter);
	}
	return 0;
}

void dfs(int x, int y)
{
	map[x][y]=1;
	place[2*step+1]=x+'1';
	place[2*step]=y+'A';
	step++;
	if(step==height*width)
	{
		ifFound=1;
		return ;
	}	
	if(x-1>=0 && y-2>=0 && !map[x-1][y-2] && !ifFound)
	{
		dfs(x-1,y-2);
		if(ifFound)
			return ;
		step--;map[x-1][y-2]=0;
		place[2*step+1]=place[2*step]=0;
	}
	if(x+1<height && y-2>=0 && !map[x+1][y-2] && !ifFound)
	{
		dfs(x+1,y-2);
		if(ifFound)
			return ;
		step--;map[x+1][y-2]=0;
		place[2*step+1]=place[2*step]=0;
	}
	if(x-2>=0 && y-1>=0 && !map[x-2][y-1] && !ifFound)
	{
		dfs(x-2,y-1);
		if(ifFound)
			return ;
		step--;map[x-2][y-1]=0;
		place[2*step+1]=place[2*step]=0;
	}
	if(x+2<height && y-1>=0 && !map[x+2][y-1] && !ifFound)
	{
		dfs(x+2,y-1);
		if(ifFound)
			return ;
		step--;map[x+2][y-1]=0;
		place[2*step+1]=place[2*step]=0;
	}
	if(x-2>=0 && y+1<width && !map[x-2][y+1] && !ifFound)
	{
		dfs(x-2,y+1);
		if(ifFound)
			return ;
		step--;map[x-2][y+1]=0;
		place[2*step+1]=place[2*step]=0;
	}	
	if(x+2<height && y+1<width && !map[x+2][y+1] && !ifFound)
	{
		dfs(x+2,y+1);
		if(ifFound)
			return ;
		step--;map[x+2][y+1]=0;
		place[2*step+1]=place[2*step]=0;
	}
	if(x-1>=0 && y+2<width && !map[x-1][y+2] && !ifFound)
	{
		dfs(x-1,y+2);
		if(ifFound)
			return ;
		step--;map[x-1][y+2]=0;
		place[2*step+1]=place[2*step]=0;
	}
	if(x+1<height && y+2<width && !map[x+1][y+2] && !ifFound)
	{
		dfs(x+1,y+2);
		if(ifFound)
			return ;
		step--;map[x+1][y+2]=0;
		place[2*step+1]=place[2*step]=0;
	}
	map[x][y]=0;
	return ;
}
