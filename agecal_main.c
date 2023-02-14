#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "agecal_header.h"


int main()
{
	char name[20];
	int date,mon,year=0;
	printf("\nEnter your name : ");
	scanf("%s",name);
	printf("\nEnter your Date Of Birth (dd/mm/yyyy) : ");
	scanf("%d/%d/%d",&date,&mon,&year);
	int val = check_valid(date,mon,year);
	if(val==0)
	{
		printf("Entered date format is wrong!!\n");
	}
	else
	{
		int days= diff_days(date+1,mon-1,year-1900);
		int yr=days/365;
		printf("\nHi %s! Your age is %d.\n",name,yr);
	        printf("\nYou are lived for %d days!!!\n",days);	
		
	}
}


