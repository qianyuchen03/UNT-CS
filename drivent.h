//Qianyu Chen
//Computer Science II 1040

#ifndef DRIVENT_H
#define DRIVENT_H
#include <string>
#include <stdio.h>
using namespace std;

class Driver
{

	private:
		int driverid;         //declares private variables
		string driverfname;
		string driverlname;
		int capacity;
		bool handicap;
		float drivrating;
		bool available;
		bool drivepets;
		string drivenotes;

	public:
		Driver();     //declares default constructor
		Driver(int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes);
		void setautoid();
                void setfirstname(string fname);
		void setlastname(string lname);
		void setcapacity(int cap);
		void setavail(bool avail);
                void sethandi(bool hand);
                void setrate(float rate);
                void setpet(bool pet);
		void setnotes(string notes);

		int getid();		//declares get functions
                string getfirstname();
		string getlastname();
		int getcapacity();
		bool getavail();
                bool gethandi();
                float getrate();
                bool getpet();
		string getnotes();
		virtual void printinfo();     //declares virtual print function
};
#endif
