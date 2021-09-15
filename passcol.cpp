//Qianyu Chen
//Computer Science II 1040

#include "passcol.h"
#include "passent.h"
#include "drivent.h"
#include "drivcol.h"
#include "rident.h"
#include "ridcol.h"
#include <vector>
#include <stdlib.h>
#include <ios>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

extern Passengers p_colvar;
extern Drivers d_colvar;
extern Rides r_colvar;

Passengers::Passengers()     //default constructor
{
	passcount = 0;
}

int Passengers::getcount()    //returns number of passengers
{
	return passcount;
}
void Passengers::inccount()	//increments number of passengers
{
	passcount++;
}
void Passengers::deccount()	//decrements number of passengers
{
	passcount--;
}


void Passengers::addpass(Passenger p_entvar)   //defines add passenger function
{
	passent.push_back(p_entvar);
	inccount();
}

void Passengers::editpass(int pid)		//defines edit passenger function
{
	long unsigned int i;
	int c = 0;

	for(i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			string npay;
			bool nhand;
			float nrate;
			bool npet;

			cout << "Enter the new payment method:" << endl;		//sets new data
				cin >> npay;
				passent.at(i).setpay(npay);
			cout << "Enter if handicapped service is needed (0 = no, 1 = yes):" << endl;
				cin >> nhand;
				passent.at(i).sethandi(nhand);
			cout << "Enter the new rating required:" << endl;
				cin >> nrate;
				passent.at(i).setrate(nrate);
			cout << "Enter if pet-friendly vehicle is needed (0 = no, 1 = yes):" << endl;
				cin >> npet;
				passent.at(i).setpet(npet);

			c++;
		}
	}
	if(c == 0)
	{
		cout << "Passenger not found. Nothing edited." << endl;
	}
}

void Passengers::deletepass(int pid)
{
	long unsigned int i;			//defines delete passenger function
	int c = 0;
	for(i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			passent.erase(passent.begin() + i);	//erases entire vector position
			cout << "Passenger - " << pid << " has been removed." << endl;
			c++;
			deccount();
			break;
		}
	}
	if(c == 0)
	{
		cout << "Passenger not found. Nothing deleted." << endl;
	}
}

void Passengers::findpass(int pid)
{
	long unsigned int i;		//defines find passenger function
	int c = 0;
	for(i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			cout << "Passenger ID " << pid << " has been found." << endl;
			c++;
		}
	}
	if(c == 0)
	{
		cout << "Passenger ID " << pid << " does NOT EXIST." << endl;
	}
}

void Passengers::printlist()
{
	string titlename = "NAMES:";		//defines printlist function
	cout << setw(25) << left << titlename;
	string titleid = "ID:";
	cout << setw(10) << left << titleid << endl;

	long unsigned int i;
	if(passent.size() == 0)
	{
		cout << "There are no passenger entries. No list printed." << endl;
	}
	for(i = 0; i < passent.size(); i++)
	{
		cout << setw(25) << left << passent.at(i).getfirstname();
		cout << setw(10) << left << passent.at(i).getid() << endl;
	}
}

void Passengers::printinfo(int pid)
{
	long unsigned int i;		//defines print info function
	int c = 0;
	for (i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			cout << "PASSENGER " << pid << "'s DETAILS" << endl;
			cout << "NAME: " << passent.at(i).getfirstname() << " " << passent.at(i).getlastname() << endl;
			cout << "ID: " << passent.at(i).getid() << endl;
			cout << "PAYMENT METHOD: " << passent.at(i).getpay() << endl;
			cout << "HANDICAPPED: ";
				if(passent.at(i).gethandi() == true)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			cout << "RATING REQUIRED: " << passent.at(i).getrate() << endl;
			cout << "PETS: ";
				if(passent.at(i).getpet() == true)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			c++;
		}
	}
	if(c == 0)
	{
		cout << "Passenger not found. Nothing printed." << endl;
	}
}
void Passengers::loadpass()
{
	ifstream fin;		//defines load passenger information function
	int id;
	string fname;
	string lname;
	string pay;
	bool handi;
	float rate;
	bool pet;

	fin.open("passengers.dat");
	fin >> passcount; fin.ignore();

	for(int i = 0; i < passcount; i++)
	{
		Passenger passvar;

		fin >> id >> fname >> lname >> pay >> handi >> rate >> pet;    //reads into vector
		passvar.setid(id);
		passvar.setfirstname(fname);
		passvar.setlastname(lname);
		passvar.setpay(pay);
		passvar.sethandi(handi);
		passvar.setrate(rate);
		passvar.setpet(pet);

		passent.push_back(passvar);

	}
	fin.close();
}
void Passengers::storepass()
{
	ofstream fout;			//defines store passenger information function
	fout.open("passengers.dat");
	fout << passcount << endl;

	long unsigned int i;
	for(i = 0; i < passent.size(); i++)		//reads into passengers.dat
	{
		fout << passent.at(i).getid() << " " << passent.at(i).getfirstname() << " " << passent.at(i).getlastname() << " " << passent.at(i).getpay() << " " << passent.at(i).gethandi() << " " << passent.at(i).getrate() << " " << passent.at(i).getpet() << endl;
	}
	fout.close();
}
void Passengers::printrides()
{
	int c = 0;			//defines print rides function
	cout << "What is the ID of the passenger?" << endl;
		int id;
		cin >> id;
	long unsigned int i;
	for(i = 0; i < passent.size(); i++)
	{
		if(id == passent.at(i).getid())
		{
			long int rid = r_colvar.p_returnride(id);	//calls the rides collection helper function
			cout << "Passenger " << id << "'s Ride = " << rid << endl;
			c++;
		}
	}
	if(c = 0)
	{
		cout << "Passenger " << id << " has not been assigned a ride." << endl;
	}
}
bool Passengers::checkpet(int pid)		//helper function that returns bool of pets
{
	long unsigned int i;
	for(i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			return passent.at(i).getpet();
		}
	}
}
bool Passengers::checkhandi(int pid)		//helper function that returns bool of handicapped
{
	long unsigned int i;
	for(i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			return passent.at(i).gethandi();
		}
	}
}
float Passengers::checkrate(int pid)		//helper function that returns float value of rate
{
	long unsigned int i;
	for(i = 0; i < passent.size(); i++)
	{
		if(pid == passent.at(i).getid())
		{
			return passent.at(i).getrate();
		}
	}
}
