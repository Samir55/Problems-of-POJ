#include<stdio.h>
#include<string.h>
#define MAXN 1000
int main()
{
	char a[MAXN+10],b[MAXN+10],c[MAXN+10],tmp_c[MAXN];
	int i,size,flag=0,count=0;
	void multiply(char *,char *,char *);
	
	scanf("%s",a);
	strcpy(tmp_c,a);
	size=strlen(tmp_c);
	for(i=0;i<size;i++)
	{
		if(tmp_c[i]!='0')
			flag=1;
		if(flag)
			c[count++]=tmp_c[i];
	}
	if(!flag)
		strcpy(c,"0");
	while(1)
	{
		scanf("%s",b);
		if(strcmp(b,"0")==0)
			break;
		multiply(a,b,c);
		strcpy(a,c);
	}
	printf("%s\n",c);
	system("pause");
	return 0;
}

void multiply(char *a,char *b,char *c)
{
	int i,j,size_a=strlen(a),size_b=strlen(b),larger_size=size_a>size_b?size_a:size_b,start_a,start_b;
	int rev_a[MAXN+10]={0},rev_b[MAXN+10]={0},tmp_c[MAXN+10];
	memset(tmp_c,0,sizeof(tmp_c));
	memset(c,0,sizeof(c));
	
	for(i=0;i<strlen(a);i++)                   
		if((a[i]-'0'))
			break;
	start_a=i;
	for(i=0;i<strlen(b);i++)
		if((b[i]-'0'))
			break;
	start_b=i;
	for(i=0;i<size_a-start_a;i++)						
		rev_a[i]=a[size_a-i-1]-'0';
	for(i=0;i<size_b-start_b;i++)
		rev_b[i]=b[size_b-i-1]-'0';	

	for(i=0;i<larger_size;i++)
	{
		tmp_c[i]+=rev_a[i]+rev_b[i];
		tmp_c[i+1]+=tmp_c[i]/10;
		tmp_c[i]%=10;				
	}
	for(j=larger_size+1;j>=0;j--)
		if(tmp_c[j])
			break;
	for(i=0;i<=j;i++)
		c[i]=tmp_c[j-i]+'0';
	c[j+1]='\0';
	
	return ;
}
