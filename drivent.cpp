//Qianyu Chen
//Computer Science II 1040

#include "drivent.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;


Driver::Driver()
{
	driverid = 0;         //default constructor
        driverfname = "none";
	driverlname = "none";
        capacity = 0;
        handicap = false;
        drivrating = 0;
        available = false;
        drivepets = false;
        drivenotes = "none";
}
Driver::Driver(int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes)
{
	driverid = id;
	driverfname = fname;
	driverlname = lname;
	capacity = cap;
	handicap = hand;
	drivrating = rate;
	available = avail;
	drivepets = pet;
	drivenotes = notes;
}


//defines set functions
void Driver::setautoid()
{
	srand(time(NULL));			//generates random 6-digit number for drive ID
	driverid = (rand()%900000) + 100000;
}
void Driver::setfirstname(string fname)
{
	driverfname = fname;
}
void Driver::setlastname(string lname)
{
	driverlname = lname;
}
void Driver::setcapacity(int cap)
{
	capacity = cap;
}
void Driver::sethandi(bool hand)
{
	handicap = hand;
}
void Driver::setrate(float rate)
{
	drivrating = rate;
}
void Driver::setavail(bool avail)
{
	available = avail;
}
void Driver::setpet(bool pet)
{
	drivepets = pet;
}
void Driver::setnotes(string notes)
{
	drivenotes = notes;
}

int Driver::getid()		//defines get functions
{
	return driverid;
}
string Driver::getfirstname()
{
	return driverfname;
}
string Driver::getlastname()
{
	return driverlname;
}
int Driver::getcapacity()
{
	return capacity;
}
bool Driver::gethandi()
{
	return handicap;
}
float Driver::getrate()
{
	return drivrating;
}
bool Driver::getavail()
{
	return available;
}
bool Driver::getpet()
{
	return drivepets;
}
string Driver::getnotes()
{
	return drivenotes;
}

void Driver::printinfo()
{
         cout << "NAME: " << getfirstname() << " " << getlastname() << endl;
         cout << "ID: " << getid() << endl;
         cout << "CAPACITY: " << getcapacity() << endl;
         cout << "HANDICAPPED CAPABLE: ";
         if(gethandi() == true)
              cout << "Yes" << endl;
         else
              cout << "No" << endl;
         cout << "RATING: " << getrate() << endl;
         cout << "PETS ALLOWED: ";
         if(getpet() == true)
              cout << "Yes" << endl;
         else
              cout << "No" << endl;
         cout << "NOTES: " << getnotes() << endl;
}
