//Qianyu Chen
//Computer Science II 1040

#ifndef PASSENT_H
#define PASSENT_H
#include <string>
#include <stdio.h>
using namespace std;

class Passenger
{

	private:
		string passfname;
		string passlname;	//declares private variables
		int passid;
		string payment;
		bool handicap;
		float rating;
		bool passpets;

	public:
		Passenger();		//declares default constructor
		Passenger(int id, string first, string last, string pay, bool hand, float rate, bool pet);   //declares parameterized constructor
		void setid(int id);          		//declares set functions
		void setautoid();
		void setfirstname(string first);
		void setlastname(string last);
		void setpay(string pay);
		void sethandi(bool hand);
		void setrate(float rate);
		void setpet(bool pet);

		int getid();		//declares get functions
		string getfirstname();
		string getlastname();
		string getpay();
		bool gethandi();
		float getrate();
		bool getpet();
};
#endif

