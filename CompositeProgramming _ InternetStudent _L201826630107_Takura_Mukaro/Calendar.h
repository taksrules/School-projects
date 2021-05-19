#ifndef CALENDAR_CPP
#define CALENDAR_CPP
#include<iomanip>
#include<vector>
#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include"Date.h"
#include"Event.h"
using namespace std;
class Calendar
{
	private:
		int day,year,month,id;
		string months[12]={"January", "February", "March","April", "May", "June","July", "August", "September","October", "November", "December"};
		vector<Event>e1;
		Date d1;
		int event_num=0;
	
	public:
		void Draw();//draws the calendar
		void setDate();//function used to determine the  date
		void Run();//is the gel that brings everything together
		void deleteEvent();//removes the event from file
		void setEvent(int i,int j,int k,string des,int d);///saves
		void showEvent();//displays events 
		void createEvent();//creates a vector of type event
		void NextMonth()//moves over to the next month
		{
			month++;
		}
		void PreviousMonth()//moves over to the previous month
		{
			month--;
		}
		void UserDate(int d,int m, int y)
	{
		day=d,year=y,month=m;
	}
};
#endif
