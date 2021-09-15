//Qianyu Chen
//Computer Science II 1040

#ifndef RIDENT_H
#define RIDENT_H

#include <string>
#include <time.h>
using namespace std;

class Ride
{
	private:
		long int rideid;	//declares ride variables
		int passenger;
		int driver;
		time_t t_pickup;
		time_t t_dropoff;
		string plocation;
		string dlocation;
		int partysize;
		bool includepet;
		string status;
		float rating;

	public:
		Ride();		//default constructor
		void setautoid();
		void setid(long int id);	//declares set functions
		void setpassenger(int pid);
		void setdriver(int did);
		void setptime(time_t ptime);
		void setdtime(time_t dtime);
		void setplocation(string ploc);
		void setdlocation(string dloc);
		void setparty(int size);
		void setpet(bool pet);
		void setstatus(string stat);
		void setrate(float rate);

		long int getid();		//declares get functions
		int getpassenger();
		int getdriver();
		time_t getptime();
		time_t getdtime();
		string getplocation();
		string getdlocation();
		int getparty();
		bool getpet();
		string getstatus();
		float getrate();
};

#endif
