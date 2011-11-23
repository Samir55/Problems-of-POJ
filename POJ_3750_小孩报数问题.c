#include<stdio.h>
#include<stdlib.h>
struct Kid
{
	char name[20];
	int num;
	struct Kid *next;
}*kid;
int main()
{
	char c;
	long n,i,w,s,count=0,outList=0;
	struct Kid *head,*tail,*p,*q;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		kid=(struct Kid *)malloc(sizeof(struct Kid));
		scanf("%s",kid->name);
		kid->num=i+1;
		if(i==0)
		{
			tail=head=kid;
			kid->next=NULL;
		}
		else
		{
			tail->next=kid;
			tail=kid;
			kid->next=NULL;
		}
	}
	kid->next=head;
	scanf("%d %c %d",&w,&c,&s);
	if(s==1||n==1)
		for(p=head;;p=p->next)
		{
			printf("%s\n",p->name);
			outList++;
			if(outList==n)
			{
				system("pause");
				return 0;
			}
		}
	for(p=head;;p=p->next)
	{
		if(p->num==w)
		{
			q=p;
			count=1;
			break;
		}	
	}
	for(p=q;;p=p->next)
	{
		if(count==s-1)
		{
			printf("%s\n",(p->next)->name);
			p->next=(p->next)->next;
			count=0;
			outList++;
			if(outList==n-1)
			{
				printf("%s\n",p->name);
				break;
			}
		}
		count++;
	}
	system("pause");
	return 0;
}
