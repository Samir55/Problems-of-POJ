#include<stdio.h>
#include<string.h>
struct DNAstring
{
	char str[51];
	int times;
}DNA[100],a;
int find( char *s )
{
	char tmp[51],c;
	int size,i,j,count=0;
	
	strcpy(tmp,s);
	size=strlen(tmp);
	for(i=0;i<size;i++)
		for(j=i;j<size;j++)
			if(tmp[i]>tmp[j])
				count++;
	return count;
}
int main()
{
	int i,j,n,m;

	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",DNA[i].str);	
		DNA[i].times=find(DNA[i].str);
	}
	for(i=0;i<m-1;i++)
		for(j=0;j<m-i-1;j++)
		{
			if(DNA[j].times>DNA[j+1].times)
			{
				a=DNA[j];
				DNA[j]=DNA[j+1];
				DNA[j+1]=a;
			}
		}
	for(i=0;i<m;i++)
		printf("%s\n",DNA[i].str);
	system("pause");
	return 0;
}
