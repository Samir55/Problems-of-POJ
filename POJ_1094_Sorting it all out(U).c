#include<stdio.h>
#include<string.h>
#define INF 30000
#define totLetters 27
int cmp[totLetters][totLetters];
long analyse[totLetters],analyse_tmp[totLetters];
int main()
{
	long tmp;
	char input[5];
	int i,j,ifEnd,nLetters,nOprts,terminateStep,anaCounter,min;
	
	while(1)
	{
		terminateStep=min=ifEnd=0;						
		for(i=0;i<totLetters;i++)
		{	
			for(j=0;j<totLetters;j++)
				cmp[i][j]=INF;
			analyse[i]=INF;
		}
		scanf("%d%d",&nLetters,&nOprts);
		getchar();
		if(!nLetters && !nOprts)
			break;
		while(nOprts--)
		{
			anaCounter=0;
			scanf("%s",input);
			if(!ifEnd)
			{
				terminateStep++;
				if(input[1]=='<')
				{
					if(cmp[input[0]-'A'][input[2]-'A']==1)
						ifEnd=1;
					else if(cmp[input[0]-'A'][input[2]-'A']==INF)
					{
						if(analyse[input[0]-'A']==INF && analyse[input[2]-'A']==INF)
						{
							analyse[input[0]-'A']=0;
							analyse[input[2]-'A']=1;
						}
						else if(analyse[input[0]-'A']==INF && analyse[input[2]-'A']!=INF)
						{
							analyse[input[0]-'A']=0;
							for(i=0;i<totLetters;i++)
							{
								if(analyse[i]>analyse[input[2]-'A']&&analyse[i]!=INF)
									analyse[i]++;
							}
							analyse[input[2]-'A']++;
						}
						else if(analyse[input[0]-'A']!=INF && analyse[input[2]-'A']==INF)
							analyse[input[2]-'A']=analyse[input[0]-'A']+1;
						else
							analyse[input[2]-'A']++;
						cmp[input[0]-'A'][input[2]-'A']=-1;
						cmp[input[2]-'A'][input[0]-'A']=1;
					}
				}
				else if(input[1]=='>')
				{
					if(cmp[input[0]-'A'][input[2]-'A']==-1)
						ifEnd=1;
					else if(cmp[input[0]-'A'][input[2]-'A']==INF)
					{
						if(analyse[input[0]-'A']==INF && analyse[input[2]-'A']==INF)
						{
							analyse[input[0]-'A']=1;
							analyse[input[2]-'A']=0;
						}
						else if(analyse[input[0]-'A']==INF && analyse[input[2]-'A']!=INF)
							analyse[input[0]-'A']=analyse[input[2]-'A']+1;
						else if(analyse[input[0]-'A']!=INF && analyse[input[2]-'A']==INF)
						{
							analyse[input[2]-'A']=0;
							for(i=0;i<totLetters;i++)
							{
								if(analyse[i]>analyse[input[0]-'A']&&analyse[i]!=INF)
									analyse[i]++;
							}
							analyse[input[0]-'A']++;
						}
						else
							analyse[input[0]-'A']++;
						cmp[input[0]-'A'][input[2]-'A']=1;
						cmp[input[2]-'A'][input[0]-'A']=-1;
					}
				}
				for(i=0;i<totLetters;i++)
					analyse_tmp[i]=analyse[i];
				for(i=0;i<totLetters;i++)
					for(j=0;j<totLetters-1;j++)
					{
						if(analyse_tmp[j]>analyse_tmp[j+1])
						{
							tmp=analyse_tmp[j];
							analyse_tmp[j]=analyse_tmp[j+1];
							analyse_tmp[j+1]=tmp;
						}
					}
				for(i=0;i<nLetters;i++)
				{
					if(analyse_tmp[i]==INF||analyse_tmp[i]==analyse_tmp[i+1])
						break;
					if(i==nLetters-1)
						ifEnd=2;
				}
			}
		}
		for(i=0;i<totLetters;i++)
			printf("%d ",analyse[i]);
		printf("\n");
		if(!ifEnd)
			printf("Sorted sequence cannot be determined.\n");
		else if(ifEnd==1)
			printf("Inconsistency found after %d relations.\n",terminateStep);
		else
		{
			printf("Sorted sequence determined after %d relations: ",terminateStep);
			for(i=0;i<nLetters;i++)
			{
				for(j=0;j<totLetters;j++)
					if(analyse[j]<analyse[min])
						min=j;
				printf("%c",min+'A');
				analyse[min]=INF;
			}
			printf("\n");
		}							
	}
	system("pause");
	return 0;
}
