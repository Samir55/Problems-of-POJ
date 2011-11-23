#include<stdio.h>
int main()
{
	int nCases,nCourses,i,score[1010],count;
	double sum,average;
	
	scanf("%d",&nCases);
	while(nCases--)
	{
		count=sum=0;
		scanf("%d",&nCourses);
		for(i=0;i<nCourses;i++)
		{
			scanf("%d",&score[i]);
			sum+=score[i];
		}
		average=sum/nCourses;
		for(i=0;i<nCourses;i++)
			if(score[i]>average)
				count++;
		printf("%.3lf%%\n",(double)count/nCourses*100);	
	}
	system("pause");
	return 0;
}
