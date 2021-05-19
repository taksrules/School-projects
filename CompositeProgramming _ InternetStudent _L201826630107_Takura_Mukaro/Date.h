#ifndef DATE_CPP
#define DATE_CPP
#include<iomanip>
#include<ctime>
#include<iostream>
#include<string>
using namespace std;
class Date
{
	private:
	    int day,month,year;
	public:
		Date()//initialises the date to the present one
		{
			
    time_t t = time(0);
    struct tm * now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;

		}
	int getDate()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
	
	
		
	
};
#endif
