//Qianyu Chen
//Computer Science II 1040

#include "rident.h"
#include "ridcol.h"
#include "drivent.h"
#include "drivcol.h"
#include "passent.h"
#include "passcol.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;


extern Passengers p_colvar;	//allows collections to be accessible in all collections
extern Drivers d_colvar;
extern Rides r_colvar;

Rides::Rides()		//default constructor
{
	ridecount = 0;
}
int Rides::getcount()		//returns number of rides
{
	return ridecount;
}
void Rides::inccount()
{
	ridecount++;		//increments number of rides
}
void Rides::deccount()
{
	ridecount--;		//decrements number of rides
}

void Rides::addride()
{
	time_t rawtime;		//time variables
	struct tm * picktime;
	struct tm * droptime;
	int year;
        int month;
        int day;
        int hour;
        int minute;

	int passid;		//declares variables
        string ploc;
        string dloc;
        int party;
        bool pets;
        float rate;
        Ride ridevar;
        char petchar;

        cout << "ADDING NEW RIDE: " << endl;
        ridevar.setautoid();
        cout << "*PLEASE NOTE* Your ride ID is: " << ridevar.getid() << endl;
        cout << "What's the ID of the passenger who requested the ride?" << endl;
             cin >> passid;
             ridevar.setpassenger(passid);		//assigns passenger id to ride entity
	     bool passpet = p_colvar.checkpet(passid);		//stores returns from passengers into variables
	     bool passhandi = p_colvar.checkhandi(passid);
	     float passrate = p_colvar.checkrate(passid);
        cout << "Where is your pickup location?" << endl;
             cin.ignore();
             getline(cin, ploc);
             ridevar.setplocation(ploc);
        cout << "Where is your drop-off location?" << endl;
             getline(cin, dloc);
             ridevar.setdlocation(dloc);
        cout << "When is your pickup time?" << endl;
        cout << "Enter year:" << endl;
             cin >> year; cin.ignore();
        cout << "Enter month:" << endl;
             cin >> month; cin.ignore();
        cout << "Enter day:" << endl;
             cin >> day; cin.ignore();
        cout << "Enter hour (1-12):" << endl;
             cin >> hour; cin.ignore();
        cout << "Enter minute (0-59):" << endl;
	     cin >> minute; cin.ignore();
	time(&rawtime);				//user inputs time using time structs
	picktime = gmtime(&rawtime);
	picktime->tm_year = year - 1900;
	picktime->tm_mon = month - 1;
	picktime->tm_mday = day;
	picktime->tm_hour = hour;
	picktime->tm_min = minute;
	picktime->tm_sec = 0;
	     ridevar.setptime(mktime(picktime));
	cout << "When is your drop off time?" << endl;
        cout << "Enter year:" << endl;
             cin >> year; cin.ignore();
        cout << "Enter month:" << endl;
             cin >> month; cin.ignore();
        cout << "Enter day:" << endl;
             cin >> day; cin.ignore();
        cout << "Enter hour (1-12):" << endl;
             cin >> hour; cin.ignore();
        cout << "Enter minute (0-59):" << endl;
             cin >> minute; cin.ignore();
        time(&rawtime);
        droptime = gmtime(&rawtime);		//user inputs time using time structs
        droptime->tm_year = year - 1900;
        droptime->tm_mon = month - 1;
        droptime->tm_mday = day;
        droptime->tm_hour = hour;
        droptime->tm_min = minute;
        droptime->tm_sec = 0;
	     ridevar.setdtime(mktime(droptime));
        cout << "What is the size of your party?" << endl;
             cin >> party;
             ridevar.setparty(party);
        cout << "Does the ride include any pets? (0 = no, 1 = yes)" << endl;
             cin >> pets;
             ridevar.setpet(pets);
        cout << "What is the ride's rating by the customer?" << endl;
             cin >> rate;
        ridevar.setrate(rate);
             string status = "Active";
        ridevar.setstatus(status);

	for(int i = 0; i < d_colvar.returnsize(); i++)	//loops through the number of drivers
	{
		if((d_colvar.checkpet(i) == passpet) && (d_colvar.checkhandi(i) == passhandi) && (d_colvar.checkcap(i) >= ridevar.getparty()) && (d_colvar.checkrate(i) >= passrate) && (d_colvar.checkavail(i) == true))
		{
			ridevar.setdriver(d_colvar.returnid(i));	//checks if driver and passenger and ride is compatible
		}							//then assigns drive id to ride entity
	}
	if(ridevar.getdriver() == 0)
	{
		cout << "No available driver found to accommodate this ride." << endl;
		cout << "Sorry for the inconvenience." << endl;
		cout << "Please wait for more drivers to be available." << endl;
	}

	rident.push_back(ridevar);	//adds ride info to ride vector
	inccount();
}

void Rides::editride(int rid)
{
	long unsigned int i;
	int c;

	for(i = 0; i < rident.size(); i++)
	{
		if(rid == rident.at(i).getid())		//defines edit ride function
                {
                        string nploc;
                        string ndloc;
			string nstat;
			float nrate;

			time_t rawtime;
        		struct tm * droptime;
        		int year;
        		int month;
        		int day;
        		int hour;
        		int minute;

                        cout << "Enter the new pick up location:" << endl;
                                cin >> nploc;
                                rident.at(i).setplocation(nploc);
                        cout << "Enter the new drop off location:" << endl;
                                cin >> ndloc;
                                rident.at(i).setdlocation(ndloc);
			cout << "When is your new drop off time?" << endl;
        		cout << "Enter year:" << endl;
             			cin >> year; cin.ignore();
        		cout << "Enter month:" << endl;
             			cin >> month; cin.ignore();
        		cout << "Enter day:" << endl;
             			cin >> day; cin.ignore();
        		cout << "Enter hour (1-12):" << endl;
             			cin >> hour; cin.ignore();
        		cout << "Enter minute (0-59):" << endl;
             			cin >> minute; cin.ignore();
        		time(&rawtime);
        		droptime = gmtime(&rawtime);
        		droptime->tm_year = year - 1900;
        		droptime->tm_mon = month - 1;
        		droptime->tm_mday = day;
        		droptime->tm_hour = hour;
        		droptime->tm_min = minute;
        		droptime->tm_sec = 0;
             			rident.at(i).setdtime(mktime(droptime));
			cout << "Enter the ride's new status (Active or Cancelled):" << endl;
				cin >> nstat;
				rident.at(i).setstatus(nstat);
			cout << "Enter the ride's new rating:" << endl;
				cin >> nrate;
				rident.at(i).setrate(nrate);

                        c++;
                }
        }
        if(c == 0)
        {
                cout << "Ride not found. Nothing edited." << endl;
        }

}
void Rides::deleteride(int rid)
{
	long unsigned int i;
        int c = 0;
        for(i = 0; i < rident.size(); i++)		//defines delete ride function
        {
                if(rid == rident.at(i).getid())
                {
                        rident.erase(rident.begin() + i);
                        cout << "Ride - " << rid << " has been removed." << endl;
                        c++;
			deccount();
                        break;
                }
        }
        if(c == 0)
        {
                cout << "Ride not found. Nothing deleted." << endl;
        }
}
void Rides::findride(int rid)
{
	long unsigned int i;
        int c = 0;
        for(i = 0; i < rident.size(); i++)
        {
                if(rid == rident.at(i).getid())		//defines find ride function
                {
                        cout << "Ride ID " << rid << " has been found." << endl;
                        c++;
                }
        }
        if(c == 0)
        {
                cout << "Ride ID " << rid << " does NOT EXIST." << endl;
        }
}
void Rides::printlist()
{
        string titleid = "ID:";
        cout << setw(10) << left << titleid << endl;		//defines print list of rides function

        long unsigned int i;
        if(rident.size() == 0)
        {
                cout << "There are no ride entries. No list printed." << endl;
        }
        for(i = 0; i < rident.size(); i++)
        {
                cout << setw(10) << left << rident.at(i).getid() << endl;
        }
}
void Rides::printinfo(int rid)
{
	long unsigned int i;			//defines print info of a ride function
        int c = 0;
        for (i = 0; i < rident.size(); i++)
        {
                if(rid == rident.at(i).getid())
                {
                        cout << "RIDE " << rid << "'s DETAILS" << endl;
                        cout << "ID: " << rident.at(i).getid() << endl;
                        cout << "PICKUP LOCATION: " << rident.at(i).getplocation() << endl;
                        cout << "DROP-OFF LOCATION: " << rident.at(i).getdlocation() << endl;
                        cout << "SIZE OF PARTY: " << rident.at(i).getparty() << endl;
                        cout << "PETS: ";
                                if(rident.at(i).getpet() == true)
                                        cout << "Yes" << endl;
                                else
                                        cout << "No" << endl;
			cout << "STATUS: " << rident.at(i).getstatus() << endl;
			cout << "RATING: " << rident.at(i).getrate() << endl;
                        c++;
                }
        }
        if(c == 0)
        {
                cout << "Ride not found. Nothing printed." << endl;
        }
}
void Rides::loadride()
{
        ifstream fin;		//defines load ride information function
        long int id;
        string ploc;
        string dloc;
	time_t ptime;
	time_t dtime;
        int party;
	bool pet;
	string stat;
        float rate;

        fin.open("rides.dat");
        fin >> ridecount; fin.ignore();

        for(int i = 0; i < ridecount; i++)
        {
		Ride ridevar;

                fin >> id >> ploc >> dloc >> ptime >> dtime >> party >> pet >> stat >> rate;
		ridevar.setid(id);
		ridevar.setplocation(ploc);
		ridevar.setdlocation(dloc);
		ridevar.setptime(ptime);
		ridevar.setdtime(dtime);
		ridevar.setparty(party);
		ridevar.setpet(pet);
		ridevar.setstatus(stat);
		ridevar.setrate(rate);

		rident.push_back(ridevar);
        }
        fin.close();
}
void Rides::storeride()
{
        ofstream fout;
        fout.open("rides.dat");		//defines store ride information function
        fout << ridecount << endl;

        long unsigned int i;
        for(i = 0; i < rident.size(); i++)
        {
                fout << rident.at(i).getid() << " " << rident.at(i).getplocation() << " " << rident.at(i).getdlocation() << " " << rident.at(i).getptime() << " " << rident.at(i).getdtime() << " " << rident.at(i).getparty() << " " << rident.at(i).getpet() << " " << rident.at(i).getstatus() << " " << rident.at(i).getrate();
        }
        fout.close();
}
void Rides::update()
{
	long unsigned int i;			//defines update rides function
	for(i = 0; i < rident.size(); i++)
	{
		time_t now = time(0);
		if(now > rident.at(i).getdtime())
		{
			string stat = "Complete";
			rident.at(i).setstatus(stat);
		}
	}
	cout << "Rides have been updated!" << endl;
}
void Rides::cleanup()
{
	long unsigned int i;
	for(i = 0; i < rident.size(); i++)	//defines clean up rides function
	{
		if((rident.at(i).getstatus() == "Complete") || (rident.at(i).getstatus() == "Cancelled"))
		{
			rident.erase(rident.begin() + i);	//deletes rides if completed or cancelled
			deccount();
		}
	}
	cout << "Rides have been cleaned up!" << endl;
}
long int Rides::p_returnride(int pid)
{
	long unsigned int i;
	for(i = 0; i < rident.size(); i++)		//helper function that returns ride id for certain passenger id
	{
		if(pid == rident.at(i).getpassenger())
		{
			return rident.at(i).getid();
		}

	}
}
long int Rides::d_returnride(int did)
{
	long unsigned int i;
	for(i = 0; i < rident.size(); i++)
	{
		if(did == rident.at(i).getdriver())	//helper function that returns ride id for certain driver id
		{
			return rident.at(i).getid();
		}
	}
}
