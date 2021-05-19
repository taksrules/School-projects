#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include"Calendar.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	
    Calendar c1;
	c1.setDate();
	c1.Run();
	return 0;
}
