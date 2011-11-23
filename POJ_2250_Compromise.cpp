#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string str1[105],str2[105];
int opt[105][105],counter;

int main()
{
	char input[35];
	int i,j,len1,len2,LCS[105][105];
	void print( int , int );

	while(scanf("%s",input)!=EOF)
	{
		i=1;
		counter=0;
		while(input[0]!='#')
		{
			str1[i++]=input;
			scanf("%s",input);
		}
		len1=i;
		i=1;
		scanf("%s",input);
		while(input[0]!='#')
		{
			str2[i++]=input;
			scanf("%s",input);
		}
		len2=i;
		memset(opt,0,sizeof(opt));
		for(i=0;i<=len1;i++)
			LCS[i][0]=0;
		for(j=0;j<len2;j++)
			LCS[0][j]=0;
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
			{
				if(str1[i]==str2[j])
				{
					LCS[i][j]=LCS[i-1][j-1]+1;
					opt[i][j]=1;
				}
				else
				{
					if(LCS[i-1][j]>LCS[i][j-1])
					{
						LCS[i][j]=LCS[i-1][j];
						opt[i][j]=0;
					}
					else
					{
						LCS[i][j]=LCS[i][j-1];
						opt[i][j]=-1;
					}
				}
			}
		print(len1,len2);
		cout<<endl;
	}
	system("pause");
	return 0;
}

void print( int i , int j )
{
	if(i==0||j==0)
		return ;
	if(opt[i][j]==1)
	{
		print(i-1,j-1);
		if(!counter)
			cout<<str1[i];
		else
			cout<<" "<<str1[i];
		counter=1;
	}
	else if(opt[i][j]==0)
		print(i-1,j);
	else
		print(i,j-1);
	return ;
}
