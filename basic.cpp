#include "drivent.h"
#include "basic.h"
#include <iostream>
using namespace std;

Basic::Basic()
{			//default constructor
	luggage = 0;
}
Basic::Basic(int lug, int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes) : Driver(id, fname, lname, cap, hand, rate, avail, pet, notes)
{
	luggage = lug;    //parameterized constructor
}
void Basic::setluggage(int lug)
{
	luggage = lug;		//defined set function
}
int Basic::getluggage()
{
	return luggage;      //defined get function
}
void Basic::printinfo()
{
	Driver::printinfo();      //inherited print function
	cout << "CARGO CAPACITY: " << getluggage() << endl;
}
