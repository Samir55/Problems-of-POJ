#include <stdio.h>

int main()
{
	int maxday, maxvalue = -1;
	int a,b,n,i;
	
	while(1) 
	{
		maxvalue = -1;
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 1; i <= n; i++) 
		{
			scanf("%d%d", &a, &b);
			if (a + b > maxvalue) 
			{
				maxvalue = a + b;
				maxday = i;
			}
		}
		if (maxvalue <= 8) printf("0\n");
		else printf("%d\n", maxday);
	}
	system("pause");
	return 0;
}
