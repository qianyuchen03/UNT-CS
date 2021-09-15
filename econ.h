using namespace std;

class Economy : public Driver    //child class
{
	private:
		int luggage;   //private variable
	public:
		Economy();   //default and parameterized constructors
		Economy(int lug, int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes);
		void setluggage(int lug);   //set + get function definitions
		int getluggage();
		void printinfo();     //print function
};
