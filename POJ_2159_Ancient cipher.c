#include<stdio.h>
#include<string.h>
#define MAXN 100
int compare(const void *p1,const void *p2)
{
	const int *a1=(const int *)p1;
	const int *a2=(const int *)p2;
	if(*a1>*a2)
		return -1;
	else if(*a1==*a2)
		return 0;
	else 
		return  1;
}
int main()
{
	char info[MAXN+20],cipher[MAXN+20];
	int i,analyseInfo[26]={0},analyseCipher[26]={0},size_info,size_cipher,flag;
	
	while(scanf("%s\n%s",info,cipher)!=EOF)
	{
		flag=0;
		size_info=strlen(info);
		size_cipher=strlen(cipher);
		for(i=0;i<size_cipher;i++)
		{
			analyseInfo[info[i]-'A']++;
			analyseCipher[cipher[i]-'A']++;
		}
		qsort((void *)analyseInfo,26,sizeof(int),compare);
		qsort((void *)analyseCipher,26,sizeof(int),compare);
		for(i=0;i<26;i++)
			if(analyseInfo[i]!=analyseCipher[i])
			{
				flag=1;
				break;
			}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
		memset(analyseInfo,0,26);
		memset(analyseCipher,0,26);
	}
	system("pause");
	return 0;
}
