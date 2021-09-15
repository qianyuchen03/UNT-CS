//Qianyu Chen
//Computer Science II 1040

#include "drivent.h"
#include <vector>
class Drivers
{

	private:
		int drivecount;         //declares counter variable
		vector <Driver*> drivent;  //declares entity driver vector

	public:
		Drivers();
		void addriver();     //declares functions for collection
		void editdriver(int did);
		void deletedriver(int did);
		void finddriver(int did);
		void printlist();
		void printinfo(int did);
		void loaddrive();
		void storedrive();
		void printrides();
		void inccount();
		void deccount();
		int getcount();
		bool checkpet(int num);
		bool checkhandi(int num);
		int checkcap(int num);
		float checkrate(int num);
		bool checkavail(int num);
		int returnid(int num);
		int returnsize();
};
