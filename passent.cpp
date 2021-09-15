//Qianyu Chen
//Computer Science II 1040

#include "passent.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

Passenger::Passenger()
{				//default constructor
	 passfname = "none";
	 passlname = "none";
         passid = 0;
         payment = "none";
         rating = 0;
	 handicap = false;
	 passpets = false;
}
Passenger::Passenger(int id, string first, string last, string pay, bool hand, float rate, bool pet)
{
	passid = id;			//parameterized constructor
	passfname = first;
	passlname = last;
	payment = pay;
	handicap = hand;
	rating = rate;
	passpets = pet;
}


void Passenger::setid(int id)       //defines set functions
{
	passid = id;
}
void Passenger::setautoid()
{
	srand(time(NULL));			//generates random 6-digit number for passenger id
	passid = (rand()%900000) + 100000;
}
void Passenger::setfirstname(string first)
{
	passfname = first;
}
void Passenger::setlastname(string last)
{
	passlname = last;
}
void Passenger::setpay(string pay)
{
	payment = pay;
}
void Passenger::sethandi(bool hand)
{
	handicap = hand;
}
void Passenger::setrate(float rate)
{
	rating = rate;
}
void Passenger::setpet(bool pet)
{
	passpets = pet;
}

int Passenger::getid()         //defines get functions
{
	return passid;
}
string Passenger::getfirstname()
{
	return passfname;
}
string Passenger::getlastname()
{
	return passlname;
}
string Passenger::getpay()
{
	return payment;
}
bool Passenger::gethandi()
{
	return handicap;
}
float Passenger::getrate()
{
	return rating;
}
bool Passenger::getpet()
{
	return passpets;
}


