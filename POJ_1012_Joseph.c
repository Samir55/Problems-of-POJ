/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int *people,k,i,m,count,outList;

	while(1)
	{
		scanf("%d",&k);
		if(k==0)
			break;
		people=(int *)malloc(sizeof(int)*2*k);
		for(m=k+1;;m++)
		{
			memset(people,1,sizeof(people)*2*k);
			count=0;
			outList=0;
			for(i=0;;i++)
			{
				if(people[i%(2*k)]==0)
					continue;
				else
				{
					count++;
					if(count==m)
					{
						if((i%(2*k))<k)
							break;
						else
						{
							people[i%(2*k)]=0;
							count=0;
							outList++;//printf("%d\n",outList);
							if(outList==k)
								goto result;
						}
					}
				}
			}
		}
		result: printf("%d\n",m);
	}
	return 0;
}
*/
#include <stdio.h>

/*#include <time.h>*/

#include <string.h>



int main()

{

	int arr[15],now,bad,k,m=0;

	memset(arr,0,15*sizeof(int));

	while(1)

	{

	m=0;

	scanf("%d",&k);

	if(k==0)break;


	if(arr[k]==0)

        {

		

	while(1)

	{

		m++;

		bad=k*2;
		now=0;


		while(1)

		{

			now=(now+m-1)%bad+1;

			if(now>k)

			{

				bad--;

				now--;

			}

			else

				break;

		}

		
		if(bad==k){arr[k]=m;break;}

	}

	}


	printf("%d\n",arr[k]);

		

	}



}
