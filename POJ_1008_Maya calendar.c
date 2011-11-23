#include<stdio.h>
#include<string.h>
char tmp[10];
int main()
{
	char Haab_month[10];
	int nCases,Haab_num,Haab_year,Tzolkin_year,Tzolkin_num,tmp1;
	long total_day;
	int dayCalculatorForHaab( char * );
	void dayCalculatorForTzolkin( int );
	
	scanf("%d",&nCases);
	printf("%d\n",nCases);
	while(nCases--)
	{
		scanf("%d. %s %d",&Haab_num,Haab_month,&Haab_year);
		total_day=Haab_year*365+dayCalculatorForHaab(Haab_month)+Haab_num;
		Tzolkin_year=total_day/260;
		Tzolkin_num=total_day%13+1;
		tmp1=total_day%20;
		dayCalculatorForTzolkin(tmp1);
		printf("%d %s %d\n",Tzolkin_num,tmp,Tzolkin_year);
	}
	system("pause");
	return 0;
}

int dayCalculatorForHaab( char *s )
{
	char month[20][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", 
				        "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", 
				        "muan", "pax", "koyab", "cumhu","uayet"};
	int i;
	
	for(i=0;i<19;i++)
		if(strcmp(month[i],s)==0)
			break;
	return i*20;
}

void dayCalculatorForTzolkin( int i )
{
	char day[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",
					  "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", 
					  "cib", "caban", "eznab", "canac", "ahau"};
					  
	strcpy(tmp,day[i]);
	return ;
}
