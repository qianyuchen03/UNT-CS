//Qianyu Chen
//Computer Science II 1040
//Partly Based on David Keathly's items.cpp File

#include "drivcol.h"
#include "drivent.h"
#include "econ.h"
#include "basic.h"
#include "group.h"
#include "lux.h"
#include "passent.h"
#include "passcol.h"
#include "rident.h"
#include "ridcol.h"
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <ios>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

extern Passengers p_colvar;	//makes the collection classes accessible in all classes
extern Drivers d_colvar;
extern Rides r_colvar;

Drivers::Drivers()
{				//default constructor
	drivecount = 0;
}
int Drivers::getcount()
{
	return drivecount;	//returns number of drivers
}
void Drivers::inccount()
{
	drivecount++;		//increments number of drivers
}
void Drivers::deccount()
{
	drivecount--;		//decrements number of drivers
}

void Drivers::addriver()
{
	int id;
        string fname;           //declares variables
        string lname;
        int capacity;
        bool handi;
        float rate;
        bool avail;
        bool pets;
	char luxury;
	int lug;
	char st;
        string notes;
	Driver drivar;
	Driver *temp;

	cout << "ADDING NEW DRIVER:" << endl;           //allows user to read in and set driver
        cout << "What is your first name?" << endl;
             cin >> fname;
        cout << "What is your last name?" << endl;
             cin >> lname;
             drivar.setautoid();
	     id = drivar.getid();
        cout << "*KEEP NOTE* Your ID is " << drivar.getid() << endl;

        cout << "What is your vehicle's passenger capacity?" << endl;
             cin >> capacity;
	cout << "What is your cargo/luggage capacity? (Suitcases, large items)" << endl;
	     cin >> lug;
	cout << "Do you own a luxury vehicle? (Y = yes, N = no)" << endl;
	     cin >> luxury;
        cout << "Are you able to offer handicapped service? (0 = no, 1 = yes)" << endl;
             cin >> handi;
        cout << "What is your driver rating?" << endl;
             cin >> rate;
        cout << "Are you available? (0 = no, 1 = yes)" << endl;
             cin >> avail;
        cout << "Can you carry pets? (0 = no, 1 = yes)" << endl;
             cin >> pets;
        cout << "Do you have any more notes?" << endl;
             cin.ignore();
             getline(cin, notes);

	if(capacity == 1 || capacity == 2)
		temp = new Economy(lug, id, fname, lname, capacity, handi, rate, avail, pets, notes);
	else if(capacity == 3 || capacity == 4)
		temp = new Basic(lug, id, fname, lname, capacity, handi, rate, avail, pets, notes);
	else if(capacity >= 5 && capacity <= 8)
		temp = new Group(lug, id, fname, lname, capacity, handi, rate, avail, pets, notes);
	else if(luxury == 'Y')
	{
		cout << "What type of luxury vehicle do you drive?" << endl;
		cout << "C - Corvette(1 pass)" << endl;
		cout << "L - Limo(9+ pass)" << endl;
		cout << "T - Tesla(3-4 pass)" << endl;
			cin >> st;
		temp = new Luxury(lug, st, id, fname, lname, capacity, handi, rate, avail, pets, notes);
	}

	drivent.push_back(temp);		//adds another driver to the vector
	inccount();
}
void Drivers::editdriver(int did)
{
					//defines edit driver function
	int c = 0;
	for(auto it = drivent.begin(); it != drivent.end(); it++)
	{
		if(did == (*it)->getid())
		{
			int ncap;
			bool nhand;
			float nrate;
			bool navail;
			bool npet;
			string nnote;

			cout << "Enter the new capacity:" << endl;
				cin >> ncap;
				(*it)->setcapacity(ncap);
			cout << "Enter if handicapped service is needed (0 = no, 1 = yes):" << endl;
				cin >> nhand;
				(*it)->sethandi(nhand);
			cout << "Enter the new rating:" << endl;
				cin >> nrate;
				(*it)->setrate(nrate);
			cout << "Enter whether available (0 = no, 1 = yes):" << endl;
				cin >> navail;
				(*it)->setavail(navail);
			cout << "Enter if vehicle is pet-friendly (0 = no, 1 = yes):" << endl;
				cin >> npet;
				(*it)->setpet(npet);
			cout << "Enter any modified notes:" << endl;
				cin.ignore();
				getline(cin, nnote);
				(*it)->setnotes(nnote);

			c++;
		}
	}
	if(c == 0)
	{
		cout << "Driver not found. Nothing edited." << endl;
	}

}
void Drivers::deletedriver(int did)
{
			//defines delete driver function
	int c = 0;
	for(unsigned int i = 0; i <  drivent.size(); i++)
	{
		if(drivent.at(i)->getid() == did)
		{
			drivent.erase(drivent.begin() + i);
			cout << "Driver - " << did << " has been removed." << endl;
			c++;
			deccount();
			break;
		}
	}
	if(c == 0)
	{
		cout << "Driver not found. Nothing deleted." << endl;
	}

}
void Drivers::finddriver(int did)
{
        		//defines find driver function
        int c = 0;
        for(int i = 0; i < drivecount; i++)
        {
                if(did == drivent[i]->getid())
                {
                        cout << "Driver ID " << did << " has been found." << endl;
                        c++;
                }
        }
        if(c == 0)
        {
                cout << "Driver ID " << did << " does NOT EXIST." << endl;
        }
}
void Drivers::printlist()
{
	string titlename = "NAMES:";		//defines print list of drivers function
        cout << setw(25) << left << titlename;
        string titleid = "ID:";
        cout << setw(10) << left << titleid << endl;

        if(drivecount == 0)
        {
                cout << "There are no driver entries. No list printed." << endl;
        }
        for(auto it = drivent.begin(); it != drivent.end(); it++)
        {
                cout << setw(25) << left << (*it)->getfirstname();
                cout << setw(10) << left << (*it)->getid() << endl;
        }
}
void Drivers::printinfo(int did)
{
        			//defines print info of a driver function
        int c = 0;
        for (auto it = drivent.begin(); it != drivent.end(); it++)
        {
                if(did == (*it)->getid())
                {
                        cout << "DRIVER " << did << "'s DETAILS" << endl;
                        cout << "NAME: " << (*it)->getfirstname() << " " << (*it)->getlastname() << endl;
                        cout << "ID: " << (*it)->getid() << endl;
                        cout << "CAPACITY: " << (*it)->getcapacity() << endl;
                        cout << "HANDICAPPED CAPABLE: ";
                                if((*it)->gethandi() == true)
                                        cout << "Yes" << endl;
                                else
                                        cout << "No" << endl;
                        cout << "RATING: " << (*it)->getrate() << endl;
                        cout << "PETS ALLOWED: ";
                                if((*it)->getpet() == true)
                                        cout << "Yes" << endl;
                                else
                                        cout << "No" << endl;
			cout << "NOTES: " << (*it)->getnotes() << endl;
			if(typeid(**it) == typeid(Economy))
			{
				Economy *tempecon = dynamic_cast<Economy*> (*it);
				cout << "LEVEL: Economy" << endl;
				cout << "CARGO CAPACITY: " << tempecon->getluggage() << endl;
			}
			else if(typeid(**it) == typeid(Basic))
			{
				Basic *tempbas = dynamic_cast<Basic*> (*it);
				cout << "LEVEL: Basic" << endl;
				cout << "CARGO CAPACITY: " << tempbas->getluggage() << endl;
			}
			else if(typeid(**it) == typeid(Group))
			{
				Group *tempgr = dynamic_cast<Group*> (*it);
				cout << "LEVEL: Group" << endl;
				cout << "CARGO CAPACITY: " << tempgr->getluggage() << endl;
			}
			else if(typeid(**it) == typeid(Luxury))
			{
				Luxury *templux = dynamic_cast<Luxury*> (*it);
				cout << "LEVEL: Luxury" << endl;
				cout << "CARGO CAPACITY: " << templux->getluggage() << endl;
        			if(templux->getstyle() == 'C')
               				 cout << "Vehicle: 2020 Corvette - Top condition" << endl;
        			else if(templux->getstyle() == 'L')
                			cout << "Vehicle: Stretch Limo - Stocked bar, WiFi, TV, Lights" << endl;
        			else if(templux->getstyle() == 'T')
                			cout << "Vehicle: 2019 Tesla Model S - Top condition, Battery powered" << endl;
        		}
                        c++;
                }
        }
        if(c == 0)
        {
                cout << "Driver not found. Nothing printed." << endl;
        }
}
void Drivers::loaddrive()
{
        ifstream fin;		//defines load driver information function
        int id;
        string fname;
	string lname;
        int cap;
        bool handi;
        float rate;
	bool avail;
        bool pet;
	string notes;
	int drivetype;
	int lug;
	char style;
	Driver *temp;

        fin.open("drivers.dat");
        fin >> drivecount; fin.ignore();

        for(int i = 0; i < drivecount; i++)
        {
                fin >> id >> fname >> lname >> cap >> handi >> rate >> avail >> pet >> notes >> drivetype;

		if(drivetype == 1)
		{
			cout << "Economy" << endl;
			fin >> lug;
			Economy * mydriver = new Economy(lug, id, fname, lname, cap, handi, rate, avail, pet, notes);
			drivent.push_back(mydriver);
		}
		else if(drivetype == 2)
		{
			cout << "Basic" << endl;
			fin >> lug;
			Basic * mydriver = new Basic(lug, id, fname, lname, cap, handi, rate, avail, pet, notes);
			drivent.push_back(mydriver);
		}
		else if(drivetype == 3)
		{
			cout << "Group" << endl;
			fin >> lug;
			Group * mydriver = new Group(lug, id, fname, lname, cap, handi, rate, avail, pet, notes);
			drivent.push_back(mydriver);
		}
		else if(drivetype == 4)
		{
			cout << "Luxury" << endl;
			fin >> lug >> style;
			Luxury * mydriver = new Luxury(lug, style, id, fname, lname, cap, handi, rate, avail, pet, notes);
			drivent.push_back(mydriver);
		}
        }
        fin.close();
}
void Drivers::storedrive()
{
        ofstream fout;
        fout.open("drivers.dat");		//defines store driver information function
        fout << drivecount << endl;

        Driver *temp;
        for(auto it  = drivent.begin(); it != drivent.end(); it++)
        {
		temp = *it;
                fout << temp->getid() << " " << temp->getfirstname() << " " << temp->getlastname() << " " << temp->getcapacity() << " " << temp->gethandi() << " " << temp->getrate() << " " << temp->getpet() << " " << temp->getnotes() << " ";

		if(typeid(**it) == typeid(Economy))
		{
			Economy *tempecon = dynamic_cast<Economy*> (temp);
			fout << "1 " << tempecon->getluggage() << endl;
		}
		else if(typeid(**it) == typeid(Basic))
		{
			Basic *tempbas = dynamic_cast<Basic*> (temp);
			fout << "2 " << tempbas->getluggage() << endl;
		}
		else if(typeid(**it) == typeid(Group))
		{
			Group *tempgro = dynamic_cast<Group*> (temp);
			fout << "3 " << tempgro->getluggage() << endl;
		}
		else if(typeid(**it) == typeid(Luxury))
		{
			Luxury *templux = dynamic_cast<Luxury*> (temp);
			fout << "4 " << templux->getluggage() << " " << templux->getstyle() << endl;
		}

	}
        fout.close();
}
void Drivers::printrides()
{
	int c = 0;			//defines print ride assigned to driver function
        cout << "What is the ID of the driver?" << endl;
                int id;
                cin >> id;
        for(auto it = drivent.begin(); it !=  drivent.end(); it++)
        {
                if(id == (*it)->getid())
                {
                        long int rid = r_colvar.d_returnride(id);
                        cout << "Driver " << id << "'s Ride = " << rid << endl;
			c++;
                }
        }
	if(c = 0)
	{
		cout << "Driver " << id << " has not been assigned a ride." << endl;
	}
}
int Drivers::returnsize()
{
	return drivecount;		//helper function that returns size of drive vector
}
bool Drivers::checkpet(int num)
{
	for(int i = 0; i < drivecount; i++)
	{
		if(num == i)
			return drivent[i]->getpet();
	}
	//helper function that returns pet bool of specified driver
}
bool Drivers::checkhandi(int num)
{
	for(int i = 0; i < drivecount; i++)
	{
		if(num == i)
			return drivent[i]->gethandi();
	}
	//helper function that returns handicapped bool of specified driver
}
int Drivers::checkcap(int num)
{
	for(int i = 0; i < drivecount; i++)
	{
		if(num == i)
			return drivent[i]->getcapacity();
	}
	//helper function that returns capacity of specified driver
}
float Drivers::checkrate(int num)
{
	for(int i = 0; i < drivecount; i++)
	{
		if(num == i)
			return drivent[i]->getrate();
	}
	//helper function that returns rating of specified driver
}
bool Drivers::checkavail(int num)
{
	for(int i = 0; i < drivecount; i++)
	{
		if(num == i)
			return drivent[i]->getavail();
	}
	//helper function that returns bool availability of specified driver
}
int Drivers::returnid(int num)
{
	for(int i = 0; i < drivecount; i++)
	{
		if(num == i)
			return drivent[i]->getid();
	}
	//helper function that returns id of specified driver
}
