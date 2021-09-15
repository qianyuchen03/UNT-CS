using namespace std;

class Group : public Driver      //child class
{
        private:
                int luggage;     //private variable
        public:
		Group();	//default and parameterized constructors
                Group(int lug,int id, string fname, string lname, int cap, bool hand, float rate, bool avail, bool pet, string notes);
                void setluggage(int lug);    //set + get functions
                int getluggage();
                void printinfo();     //print function
};
