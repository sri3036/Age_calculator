#include<stdio.h>
#include<time.h>
#include <math.h>

int check_valid(int date,int mon,int year)
{
	int flag=1;
	if(year>1800 && year<9999 && date>0 && date<=31 && mon>0 && mon<=12)
	{
		if(mon == 1 || mon==3 || mon==5 || mon==7 || mon ==8 || mon ==10 || mon ==12)
		{
			if(date>31)
			{
				printf("1");
				printf("Your date and month is mismatched\n");
				flag=0;
				return 0;
			}
		}
		else if(mon==2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			if(date>29)
			{
				printf("2 ");
				printf("Your date and month is mismatched\n");
				flag=0;
				return 0;
			}
		}
		else
		{
			if(date>30)
			{
				printf("3 ");
				printf("Your date and month is mismatched\n");
				flag=0;
				return 0;
			}
		}
	}
	else
	{
		flag=0;
	}
	return flag;
}

int diff_days(int date,int mon,int year)
{
	time_t rawtime=time(NULL);
	struct tm *tm1=localtime(&rawtime);
	struct tm tm2={0};
	tm2.tm_year=year;
	tm2.tm_mon=mon;
	tm2.tm_mday=date;
	if(tm1==NULL)
	{
		puts("The date can't get from the system");
	}
        else
	{
		time_t t1=mktime(tm1);
		time_t t2=mktime(&tm2);
		double dt = difftime(t1,t2);
		int days =round(dt / 86400);
		return days;
	}
}











