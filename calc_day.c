#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef unsigned char bool;
unsigned int month_day[12]={31, 28, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31};

enum
{
	false = 0,
	true = 1,
};

bool is_leap_year(unsigned long year)
{
	if((0 == (year % 4)) && (0 != (year %100)))
	{
		return true;
	}
	else if (0 == (year % 400))
	{
		return true;
	}
	else if((0 == (year % 3200)) && (0 == (year % 172800)))
	{
		return true;
	}
	
	return false;
}

int calc_month(unsigned char leap, unsigned int month)
{
	unsigned int i = 0;
	unsigned int day = 0;
	
	for(i=0; i<(month-1); i++)
	{
		day += month_day[i];
	}
	
	if((true == leap) && (2 < month))
	 {
		day++;
	}
	
	return day;
}

int calc_day(unsigned long year, unsigned int month, unsigned int day)
{
	unsigned int leap_year = false;
	unsigned int sum_day = 0;
	
	leap_year = is_leap_year(year);
	sum_day = calc_month(leap_year, month);
	sum_day += day;

	return sum_day;
}

int main(int argc, char* argv[])
{
	unsigned int year = 0;
	unsigned int month  = 0;
	unsigned int day = 0;
	unsigned int sum_day = 0;
	
	printf("input year/month/day :\n");
	scanf("%d %d %d",&year, &month, &day);
	sum_day = calc_day(year, month, day);
	printf("sum_day = %d.\n", sum_day);
	
	return 0;
}


