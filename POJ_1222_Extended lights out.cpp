#include<iostream>
#include<cstring>
#define MAXN 8
#define INF 100000
using namespace std;

int map[MAXN][MAXN]={0},press[MAXN][MAXN],caseCount=0;

int main()
{
	int i,j,nCases;
	void search();
	
	cin>>nCases;
	while(nCases--)
	{
		caseCount++;
		for(i=1;i<6;i++)
			for(j=1;j<7;j++)
				cin>>map[i][j];
		search();
	}
	return 0;
}

void search()
{
	int i,j,k,l,m,n,o,p;
	
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
				for(l=0;l<2;l++)
					for(m=0;m<2;m++)
						for(n=0;n<2;n++)
						{
							memset(press,0,sizeof(press));
							press[1][1]=i;press[1][2]=j;press[1][3]=k;
							press[1][4]=l;press[1][5]=m;press[1][6]=n;
							for(o=2;o<6;o++)
								for(p=1;p<7;p++)
									if((map[o-1][p]+press[o-1][p]+press[o-1][p-1] 
									    +press[o-1][p+1]+press[o-2][p])%2==1)
										press[o][p]=1; 
							for(o=1;o<7;o++)
								if((map[5][o]+press[5][o-1]+press[5][o]+press[5][o+1]
								   +press[4][o])%2==1)
								   break;
							if(o==7)
							{
								cout<<"PUZZLE #"<<caseCount<<endl;
								for(o=1;o<6;o++)
									for(p=1;p<7;p++)
									{	
										if(p==1)
											cout<<press[o][p];
										else
											cout<<" "<<press[o][p];
										if(p==6)
											cout<<endl;
									}		
								return ;		
							}
						}
}
