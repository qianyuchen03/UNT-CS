#include "drivent.h"
#include "econ.h"
#include <iostream>
using namespace std;

Economy::Economy()    //defined default constructor
{
	luggage = 0;
}
Economy::Economy(int lug, int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes) : Driver(id, fname, lname, cap, hand, rate, avail, pet, notes)
{
	luggage = lug;            //defined parameterized constructor
}
void Economy::setluggage(int lug)   //defined set function
{
	luggage = lug;
}
int Economy::getluggage()     //defined get function
{
	return luggage;
}
void Economy::printinfo()    //defined print function
{
	Driver::printinfo();
	cout << "CARGO CAPACITY: " << getluggage() << endl;
}
