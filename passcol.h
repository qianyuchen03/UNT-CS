//Qianyu Chen
//Computer Science II 1040

#include "passent.h"
#include <vector>

class Passengers
{

	public:
		Passengers();     //declares default constructor
		void addpass(Passenger p_entvar);	//declares functions for collection
		void editpass(int pid);
		void deletepass(int pid);
		void findpass(int pid);
		void printlist();
		void printinfo(int pid);
		void loadpass();
		void storepass();
		void printrides();
		void inccount();
		void deccount();
		int getcount();
		bool checkpet(int pid);
		bool checkhandi(int pid);
		float checkrate(int pid);

	private:
		int passcount;
		vector <Passenger> passent;	//declares entity vector
};

