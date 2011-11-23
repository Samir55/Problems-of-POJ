#include<iostream>
#define MAXN 100+10
using namespace std;
char map[MAXN][MAXN];
int main()
{
	int height,width,i,j,deposit;
	void FloodFill(int, int);
	
	while(1)
	{
		cin>>height>>width;
		if(!height)
			break;
		deposit=0;
		for(i=1;i<=height;i++)
			for(j=1;j<=width;j++)
				cin>>map[i][j];
		for(i=1;i<=height;i++)
			for(j=1;j<=width;j++)
			{
				if(map[i][j]=='@')
				{
					FloodFill(i,j);
					deposit++;
				}
			}
		cout<<deposit<<endl;
	}
	return 0;
}

void FloodFill(int i, int j)
{
	map[i][j]='$';
	if(map[i-1][j-1]=='@')	FloodFill(i-1,j-1);
	if(map[i-1][j]=='@')	FloodFill(i-1,j);
	if(map[i-1][j+1]=='@')	FloodFill(i-1,j+1);
	if(map[i][j-1]=='@')	FloodFill(i,j-1);
	if(map[i][j+1]=='@')	FloodFill(i,j+1);
	if(map[i+1][j-1]=='@')	FloodFill(i+1,j-1);
	if(map[i+1][j]=='@')	FloodFill(i+1,j);
	if(map[i+1][j+1]=='@')	FloodFill(i+1,j+1);
	return ;
}

