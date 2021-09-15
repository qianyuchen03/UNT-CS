//Qianyu Chen
//Computer Science II 1040

#include "rident.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <time.h>
using namespace std;

Ride::Ride()
{
	rideid = 0;		//default constructor
	passenger = 0;
	driver = 0;
	t_pickup = time(NULL);
	t_dropoff = time(NULL);
	plocation = "none";
	dlocation = "none";
	partysize = 0;
	includepet = false;
	status = "none";
	rating = 0;
}
void Ride::setid(long int id)
{
	rideid = id;
}

void Ride::setautoid()
{
	int i;
	int j;			//generates random 8-digit number for ride ID
	srand(time(NULL));

	i = rand()%9 + 1;
	for(int a = 1; a < 4; a++)
	{
		i = i*10 + rand()%10;
	}
	for(int b = 1; b < 4; b++)
	{
		j = j*10 + rand()%10;
	}
	rideid = i*10000 + j;

}
void Ride::setpassenger(int pid)		//defines set functions
{
	passenger = pid;
}
void Ride::setdriver(int did)
{
	driver = did;
}
void Ride::setptime(time_t ptime)
{
	t_pickup = ptime;
}
void Ride::setdtime(time_t dtime)
{
	t_dropoff = dtime;
}
void Ride::setplocation(string ploc)
{
	plocation = ploc;
}
void Ride::setdlocation(string dloc)
{
	dlocation = dloc;
}
void Ride::setparty(int size)
{
	partysize = size;
}
void Ride::setpet(bool pet)
{
	includepet = pet;
}
void Ride::setstatus(string stat)
{
	status = stat;
}
void Ride::setrate(float rate)
{
	rating = rate;
}

long int Ride::getid()		//defines get functions
{
	return rideid;
}
int Ride::getpassenger()
{
	return passenger;
}
int Ride::getdriver()
{
	return driver;
}
time_t Ride::getptime()
{
	return t_pickup;
}
time_t Ride::getdtime()
{
	return t_dropoff;
}
string Ride::getplocation()
{
	return plocation;
}
string Ride::getdlocation()
{
	return dlocation;
}
int Ride::getparty()
{
	return partysize;
}
bool Ride::getpet()
{
	return includepet;
}
string Ride::getstatus()
{
	return status;
}
float Ride::getrate()
{
	return rating;
}

