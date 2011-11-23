#include<stdio.h>
char map[32][32];
int main()
{
	char direction[1200];
	int nCases,caseCount=0,cur_x,cur_y,i,j;
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		caseCount++;
		memset(map,'0',sizeof(map));
		memset(direction,0,sizeof(direction));
		scanf("%d%d%s",&cur_x,&cur_y,direction);
		for(i=0;;i++)
		{
			if(direction[i]=='E')
			{
				cur_x++;
				map[cur_x-1][cur_y-1]++;
			}
			else if(direction[i]=='W')
			{
				cur_x--;
				map[cur_x][cur_y]++;
			}
			else if(direction[i]=='N')
			{
				cur_y++;
				map[cur_x][cur_y-1]++;
			}
			else if(direction[i]=='S')
			{
				cur_y--;
				map[cur_x-1][cur_y]++;
			}
			else
				break;
		}
		printf("Bitmap #%d\n",caseCount);
		for(j=31;j>=0;j--)
			for(i=0;i<32;i++)
			{
				if(map[i][j]!='0')
					printf("X");
				else
					printf(".");
				if(i==31)
					printf("\n");
			}
		printf("\n");
	}
	system("pause");
	return 0;
}
