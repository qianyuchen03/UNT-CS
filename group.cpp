#include "drivent.h"
#include "group.h"
#include <iostream>
using namespace std;

Group::Group()
{			//default constructor
	luggage = 0;
}
Group::Group(int lug, int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes) : Driver(id, fname, lname, cap, hand, rate, avail, pet, notes)
{
	luggage = lug;     //defined parameterized constructor
}
void Group::setluggage(int lug)     //defined set function
{
	luggage = lug;
}
int Group::getluggage()       //defined get function
{
	return luggage;
}
void Group::printinfo()     //print function
{
	Driver::printinfo();
	cout << "CARGO CAPACITY: " << getluggage() << endl;
}
