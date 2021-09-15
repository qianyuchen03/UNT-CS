#include "rident.h"
#include <vector>
#include <iostream>
using namespace std;

class Rides
{

	private:
		int ridecount;
		vector <Ride> rident;

	public:
		Rides();     //declares default constructor
                void addride();       //declares functions for collec
                void editride(int rid);
                void deleteride(int rid);
                void findride(int rid);
                void printlist();
                void printinfo(int rid);
		void loadride();
		void storeride();
		void update();
		void cleanup();
		void inccount();
		void deccount();
		int getcount();
		long int p_returnride(int pid);
		long int d_returnride(int did);
};
