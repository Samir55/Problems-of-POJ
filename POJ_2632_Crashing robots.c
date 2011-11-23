#include<stdio.h>
struct ROBOT
{
	char direction;
	int x,y;
}robot[105];
int map[105][105];
int main()
{ 
	char oprt;
	int nCases,length,width,n,m,i,j,flag,robotTomove,timesTomove,crashA,crashB;
	
	scanf("%d",&nCases); 
	while(nCases--)
	{
		flag=0;
		memset(map,0,sizeof(map));
		scanf("%d%d%d%d",&width,&length,&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %c",&robot[i].x,&robot[i].y,&robot[i].direction);
			map[robot[i].x][robot[i].y]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d %c %d",&robotTomove,&oprt,&timesTomove);
			if(oprt=='L'&&!flag)
			{
				for(j=0;j<timesTomove%4;j++)
				{
					if(robot[robotTomove].direction=='W')
						robot[robotTomove].direction='S';
					else if(robot[robotTomove].direction=='S')
						robot[robotTomove].direction='E';
					else if(robot[robotTomove].direction=='E')
						robot[robotTomove].direction='N';
					else if(robot[robotTomove].direction=='N')
						robot[robotTomove].direction='W';
				}
			}
			if(oprt=='R'&&!flag)
			{
				for(j=0;j<timesTomove%4;j++)
				{
					if(robot[robotTomove].direction=='W')
						robot[robotTomove].direction='N';
					else if(robot[robotTomove].direction=='N')
						robot[robotTomove].direction='E';
					else if(robot[robotTomove].direction=='E')
						robot[robotTomove].direction='S';
					else if(robot[robotTomove].direction=='S')
						robot[robotTomove].direction='W';
				}
			}
			if(oprt=='F'&&!flag)
			{
				for(j=0;j<timesTomove;j++)
				{
					if(robot[robotTomove].direction=='W')
					{
						if(robot[robotTomove].x==1)
						{
							flag=1;
							crashA=robotTomove;
							break;
						}
						if(map[robot[robotTomove].x-1][robot[robotTomove].y])
						{
							flag=2;
							crashA=robotTomove;
							crashB=map[robot[robotTomove].x-1][robot[robotTomove].y];
							break;
						}
						else
						{
							map[robot[robotTomove].x-1][robot[robotTomove].y]=robotTomove;
							map[robot[robotTomove].x][robot[robotTomove].y]=0;
							robot[robotTomove].x--;	
						}
					}
					else if(robot[robotTomove].direction=='N')
					{
						if(robot[robotTomove].y==length)
						{
							flag=1;
							crashA=robotTomove;
							break;
						}
						if(map[robot[robotTomove].x][robot[robotTomove].y+1])
						{
							flag=2;
							crashA=robotTomove;
							crashB=map[robot[robotTomove].x][robot[robotTomove].y+1];
							break;
						}
						else
						{
							map[robot[robotTomove].x][robot[robotTomove].y+1]=robotTomove;
							map[robot[robotTomove].x][robot[robotTomove].y]=0;
							robot[robotTomove].y++;	
						}
					}
					else if(robot[robotTomove].direction=='E')
					{
						if(robot[robotTomove].x==width)
						{
							flag=1;
							crashA=robotTomove;
							break;
						}
						if(map[robot[robotTomove].x+1][robot[robotTomove].y])
						{
							flag=2;
							crashA=robotTomove;
							crashB=map[robot[robotTomove].x+1][robot[robotTomove].y];
							break;
						}
						else
						{
							map[robot[robotTomove].x+1][robot[robotTomove].y]=robotTomove;
							map[robot[robotTomove].x][robot[robotTomove].y]=0;
							robot[robotTomove].x++;	
						}
					}
					else if(robot[robotTomove].direction=='S')
					{
						if(robot[robotTomove].y==1)
						{
							flag=1;
							crashA=robotTomove;
							break;
						}
						if(map[robot[robotTomove].x][robot[robotTomove].y-1])
						{
							flag=2;
							crashA=robotTomove;
							crashB=map[robot[robotTomove].x][robot[robotTomove].y-1];
							break;
						}
						else
						{
							map[robot[robotTomove].x][robot[robotTomove].y-1]=robotTomove;
							map[robot[robotTomove].x][robot[robotTomove].y]=0;
							robot[robotTomove].y--;	
						}
					}
				}
			}	
		}
		if(!flag)
			printf("OK\n");
		else if(flag==1)
			printf("Robot %d crashes into the wall\n",crashA);
		else if(flag==2)
			printf("Robot %d crashes into robot %d\n",crashA,crashB);
	}
	system("pause");
	return 0;
}






















