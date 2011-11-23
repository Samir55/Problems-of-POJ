#include<stdio.h>

int count;
char map[25][25]={0};

int main()
{
	int W,H,i,j,x,y;
	void check (int , int);
	
	while(1)
	{
		count=0;
		memset(map,'#',sizeof(map));
		fscanf(stdin,"%d %d",&W,&H);
		if(W==0)
			break;
		for(i=1;i<=H;i++)
			fscanf(stdin,"%s",&map[i][1]);
		for(i=1;i<=H;i++)
			for(j=1;j<=W+1;j++)
			{
				if(j==W+1)
					map[i][j]='#';
				if(map[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
		check(x,y);
		printf("%d\n",count);
	}
	
	return 0;
}

void check(int x, int y)
{	
	if(map[x][y]=='#')
		return ;
	else
	{
		count++;
		map[x][y]='#';
		check(x,y+1);
		check(x,y-1);
		check(x+1,y);
		check(x-1,y);
	}
	return ;
}
