using namespace std;

class Luxury : public Driver		//child class
{
        private:
                int luggage;      //private variables
		char style;
        public:
		Luxury();     //default and parameterized constructors
                Luxury(int lug, char style, int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes);
                void setluggage(int lug);     //set functions
		void setstyle(char st);
                int getluggage();        //get functions
		char getstyle();
                void printinfo();        //print function
};
