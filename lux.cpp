#include "drivent.h"
#include "lux.h"
#include <iostream>
using namespace std;

Luxury::Luxury()
{			//default constructor
	luggage = 0;
	style = 'x';
}
Luxury::Luxury(int lug, char st, int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes) : Driver(id, fname, lname, cap, hand, rate, avail, pet, notes)
{
	luggage = lug;     //parameterized constructor
	style = st;
}
void Luxury::setluggage(int lug)    //defined set functions
{
	luggage = lug;
}
void Luxury::setstyle(char st)
{
	style = st;
}
int Luxury::getluggage()     //defined get functions
{
	return luggage;
}
char Luxury::getstyle()
{
	return style;
}
void Luxury::printinfo()
{
	Driver::printinfo();        			//inherited and defined print function
	cout << "CARGO CAPACITY: " << getluggage();
	if(getstyle() == 'C')
		cout << "Type: 2020 Corvette - Top condition" << endl;
	else if(getstyle() == 'L')
		cout << "Type: Stretch Limo - Stocked bar, WiFi, TV, Lights" << endl;
	else if(getstyle() == 'T')
		cout << "Type: 2019 Tesla Model S - Top condition, Battery powered" << endl;
}
