#ifndef EVENT_CPP
#define EVENT_CPP
#include<iomanip>

#include<iostream>
#include<string>
using namespace std;
class Event//this is the class responsible for saving and 
{
	private:int day, month, year,id;
	        string description;
		
	public:
	    void saveEvent(int i,int j,int k,string des,int d)
	    {
	    	day=i,month=j,year=k,description=des,id=d;
		}
		
		
};
#endif
