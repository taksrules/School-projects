#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include"Calendar.h"
#include"Date.h"
#include"Event.h"
#include <fstream>
using namespace std;
void Calendar::Draw()
{
	// Calculate the week for the first day in this month
    int y, c, m; 
    if (month == 1 || month == 2) 
    {
        y = (year - 1) % 100;
        c = (year - 1) / 100;;
        m = month + 12;
    }
    else
    {
        y = year % 100;
        c = year / 100;
        m = month;
    }
    int week = ((y + y / 3 + c / 4 - 2 * c + 
                26 * (m + 1) / 10) % 7 + 7) % 7; 
    bool leap = false;
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        leap = true;
    int feb;    
    if(leap==true) 
	{ feb=29; } 
	else
	{ feb=28;} 
    int Days[12]={31,feb,31,30,31,30,31,31,30,31,30,31};

    cout<<" **********************************************"<<endl;
    cout<<"              "<<months[month]<<"    "<<year<<"    "<<endl;
    cout<<"   SU     MO     TU     WE     TH     FR     SA"<<endl;
	for(int i=0;i<week;i++)
	{
		cout<<"       ";
	}
	for(int i=1;i<=Days[month];i++)
    {
    	cout<<setw(5)<<i<<"  ";
    	if((week+i)%7==0)
    	cout<<endl;
    }

}
void Calendar::setDate()
{
	day=d1.getDate();year=d1.getYear();month=d1.getMonth();
}

void Calendar::createEvent()
{
	int d,y,m,id;
	string des;
	cout<<"please enter the date in the format day month year."<<endl;
	cin>>d>>m>>y;
	cout<<"Please enter event id:"<<endl;
	cin>>id;
	cout<<"Please enter description";
	cin>>des;
	Event temp_event;	
	setEvent(d,m,y,des,id);
	temp_event.saveEvent(d,m,y,des,id);
	e1.push_back(temp_event);
	event_num++;
	
}
void Calendar::Run()
{
    char a;
    while(a!='Q')
  {
	cout<<endl<<"Press 'N': Show the calendar for the next month;"<<endl;
    cout << "Press 'P': Show the calendar for the previous month"<<endl;
    cout<<"Press 'C': Input year and month, the program will show the calendar as you inputted"<<endl;
    cout<<"Press 'A': Input year/month/day, then input a description, it will add an event to the calendar. "<<endl;
	cout<<"Press 'L': Show all events you have created, each one with an ID"<<endl;
    cout<<"Press 'D': Input event ID, delete the event with this ID"<<endl;
    cout<<"Press 'S': Input a file name, save the events you have created in this calendar program to a file on the disk"<<endl;
    cout<<"Press 'R': Input a file name, load the events you have saved"<<endl;
    cout<<"Press 'Q': Exit the program. "<<endl;
    cin>>a;
    	
if(a=='N')
    {
    	NextMonth();
    	Draw();
	}
	else if(a=='P')
	{  
	   PreviousMonth();
	   Draw();
	}
	else if(a=='C')
	{
	int d,y,m;
	cout<<"please enter the date in the format day month year."<<endl;
	cin>>d>>m>>y;
	UserDate(d,m,y);
	Draw();
	}
	else if(a=='A')
	{
		createEvent();
	}
	else if(a=='L')
	{
	 showEvent();	
	}
	else if(a=='D')
	{
	 deleteEvent();	
	}
	else if(a=='S')
	{
		string filename;
		cout<<"please eneter file name"<<endl;
		cin>>filename;
		cout<<"file saved "<<endl;
		ifstream docu;
		docu.open(filename.c_str());
		if(!docu.is_open())
		{
			cerr<<"failed"<<filename;
		}
		docu.close();
	}
	else if(a=='R')
	{
		string filename;
		cout<<"please eneter file name"<<endl;
		cin>>filename;
		cout<<"file saved "<<endl;
		ifstream docu;
		docu.open(filename.c_str());
		if(!docu.is_open())
		{
			cerr<<"failed"<<filename;
		}
		Event e2;
		int d,y,m,i;
		string des;
		docu>>d;
		docu>>m;
		docu>>y;
		docu>>des;
		docu>>i;
		e2.saveEvent(d,m,y,des,i);
		e1.push_back(e2);
		docu.close();
	}
	else if(a=='Q')
	{cout<<"EXIT"<<endl;
	}
	else
	{
		cout<<"Invalid!!!!";
	}
}
}
void Calendar::setEvent(int i,int j,int k,string des,int d)
{
	day=i,month=j,year=k;string description=des;
	id=d;
	
	ofstream inFile;
	inFile.open("Event.txt");
	inFile<<day<<" ";
	inFile<<month;inFile<<year;inFile<<description;
	inFile.close();
}
void Calendar::showEvent()
{
	string file;
    cout<<"please enter event id: "<<endl;
	cin>>id;
	ifstream OutFile;
	OutFile.open("Event.txt");
	OutFile>>file;
	for(int i=0;i<sizeof(file);i++)
	{
		

			cout<<file[i]<<"  ";
	
	}
	OutFile.close();
}
void Calendar::deleteEvent()
{
	
	string file;
	cout<<"please enter event id: "<<endl;
	cin>>id;
	ifstream OutFile;
	OutFile.open("Event.txt");
	OutFile>>file;
	OutFile.close();
	for(int i=0;i<sizeof(file);i++)
	{
		if(file[i]==id)
		{
			file[i]=NULL;
			file[i+1]=NULL;
			file[i+2]=NULL;
		}
		if(id == i)
			{
				e1.erase(e1.begin()+id-1);	
			}
    }  
	ofstream InFile;	
	InFile.open("Event.txt");
	InFile<<file;
	InFile.close();
	
		
}

