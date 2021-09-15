/*Qianyu Chen
  qianyuchen2@my.unt.edu
  Description: Implements a system that schedules drivers and passengers for rides
*/


#include <string>
#include <stdio.h>
#include <iostream>

#include "passent.h"
#include "passcol.h"
#include "drivent.h"
#include "drivcol.h"
#include "rident.h"
#include "ridcol.h"

using namespace std;

Passengers p_colvar;
Drivers d_colvar;
Rides r_colvar;

int main()
{

	cout << "-----------------------------------------" << endl;        //outputs my information
	cout << "| 	      Computer Science          |" << endl;
	cout << "|              CSCE 1040.001            |" << endl;
	cout << "|  Qianyu Chen qianyuchen2@my.unt.edu   |" << endl;
	cout << "-----------------------------------------" << endl << endl << endl;

	cout << "-----------------------------------------" << endl;       //outputs introduction
	cout << "|		 HELLO!                 |" << endl;
	cout << "|		WELCOME TO	        |" << endl;
	cout << "|    THE MEAN GREAN EAGLELIFT SYSTEM    |" << endl;
	cout << "-----------------------------------------" << endl << endl;

	int menu;		//declares class variables


	cout << "Would you like to load data from the previous run? (enter y/n)" << endl;
		char choice;
		cin >> choice;
	if(choice == 'y')
	{
		p_colvar.loadpass();    //load in collection data from file
		d_colvar.loaddrive();
		r_colvar.loadride();
	}

	while(menu != 10)	//repeatedly outputs menu
	{
		cout << "------------------------------" << endl;
		cout << "|	     MENU            |" << endl;
		cout << "| Choose an option(number):  |" << endl;
		cout << "|1. ADD                      |" << endl;
		cout << "|2. EDIT                     |" << endl;
		cout << "|3. DELETE                   |" << endl;
		cout << "|4. SEARCH                   |" << endl;
		cout << "|5. PRINT ENTRIES            |" << endl;
		cout << "|6. PRINT INFO OF AN ENTRY   |" << endl;
		cout << "|7. PRINT ASSIGNED RIDES     |" << endl;
		cout << "|8. UPDATE RIDES             |" << endl;
		cout << "|9. CLEAN UP RIDES           |" << endl;
		cout << "|10. QUIT		     |" << endl;
		cout << "------------------------------" << endl;
			cin >> menu;

		if(menu == 1)
		{
			char pdr;
			cout << "Are you a adding a passenger, driver, or ride? (enter p/d/r)" << endl;
				cin >> pdr;

			if(pdr == 'p')
			{
			        string fname;   //declares temp variables
				string lname;
        			int id;
        			string pay;
        			bool handi;
        			float rating;
        			bool pets;
        			Passenger passvar;

        			cout << "ADDING NEW PASSENGER: " << endl;    //allows user to read in name
        			cout << "What is your first name?" << endl;
					cin >> fname;
					passvar.setfirstname(fname);
				cout << "What is your last name?" << endl;
					cin >> lname;
					passvar.setlastname(lname);
					passvar.setautoid();		//sets automated id
        			cout << "*KEEP NOTE* Your ID is " << passvar.getid() << endl;
        			cout << "What is your payment preference?" << endl;		//allows user to read in payment
                			cin >> pay;
					passvar.setpay(pay);
        			cout << "Are you in need of handicapped service? (0 = no, 1 = yes)" << endl;
                			cin >> handi;			//allows user to read in handicapped
					passvar.sethandi(handi);
        			cout << "What is your default rating required?" << endl;	//allows user to read in rating
                			cin >> rating;
					passvar.setrate(rating);
        			cout << "Do you have any pets? (0 = no, 1 = yes)" << endl;   //allows user to read in pets or not
                			cin >> pets;
					passvar.setpet(pets);

				p_colvar.addpass(passvar);    //calls add passenger function and passes in entity info
			}
			else if(pdr == 'd')
			{
				d_colvar.addriver();		//calls add driver function
			}
			else if(pdr == 'r')
			{

                                r_colvar.addride();      //calls add ride function
			}
		}
		else if(menu == 2)
		{
			char pdr;
                        cout << "Are you editing a passenger, driver, or ride? (enter p/d/r)" << endl;
                                cin >> pdr;

			if(pdr == 'p')
			{
				int id;

				cout << "EDIT PASSENGER INFORMATION:" << endl;
				cout << "What is your passenger ID?" << endl;
					cin >> id;      //allows user to read in passenger id

				p_colvar.editpass(id);		//calls edit passenger function
			}
			else if(pdr == 'd')
			{
				int id;

				cout << "EDIT DRIVER INFORMATION:" << endl;
				cout << "What is your driver ID?" << endl;
					cin >> id;		//allows user to read in driver id
				d_colvar.editdriver(id);		//calls edit driver function
			}
			else if(pdr == 'r')
			{
				int id;

				cout << "EDIT RIDE INFORMATION:" << endl;
				cout << "What is your ride ID?" << endl;
					cin >> id;		//allows user to read in ride id

				r_colvar.editride(id);		//calls edit ride function
			}
		}
		else if(menu == 3)
		{
			char pdr;
			cout << "Are you deleting a passenger, driver, or ride? (enter p/d/r):" << endl;
				cin >> pdr;

			if(pdr == 'p')
			{
				cout << "DELETE PASSENGER:"  << endl;
				cout << "Enter ID of passenger to remove:" << endl;
				int id;
					cin >> id;
					p_colvar.deletepass(id);	//calls delete passenger function
			}
			else if(pdr == 'd')
			{
				cout << "DELETE DRIVER:" << endl;
				cout << "Enter ID of driver to remove:" << endl;
				int id;
					cin >> id;
					d_colvar.deletedriver(id);	//calls delete driver function
			}
			else if(pdr == 'r')
			{
				cout << "DELETE RIDE:" << endl;
				cout << "Enter the ride ID to remove:" << endl;
				int id;
					cin >> id;
					r_colvar.deleteride(id);	//calls delete ride function
			}
		}
		else if(menu == 4)
		{
			char pdr;
			cout << "Are you searching for a passenger, driver, or ride? (enter p/d/r):" << endl;
				cin >> pdr;
			if(pdr == 'p')
			{
				int id;
				cout << "Enter the passenger ID to search for:" << endl;
					cin >> id;
				p_colvar.findpass(id);		//calls find passenger function
			}
			else if(pdr == 'd')
			{
				int id;
				cout << "Enter the driver ID to search for:" << endl;
					cin >> id;
				d_colvar.finddriver(id);	//calls find driver function
			}
			else if(pdr == 'r')
			{
				int id;
				cout << "Enter the ride ID to search for:" << endl;
					cin >> id;
				r_colvar.deleteride(id);	//calls find ride function
			}
		}
		else if(menu == 5)
		{
			char pdr;
			cout << "Are you printing passenger, driver, or ride entries? (enter p/d/r):" << endl;
				cin >> pdr;
			if(pdr == 'p')
			{
				cout << "-PRINTED LIST OF ALL PASSENGER ENTRIES-" << endl;
				p_colvar.printlist();		//calls print list function for passengers
			}
			else if(pdr == 'd')
			{
				cout << "-PRINTED LIST OF ALL DRIVER ENTRIES-" << endl;
				d_colvar.printlist();		//calls print list function for drivers
			}
			else if(pdr == 'r')
			{
				cout << "-PRINTED LIST OF ALL RIDE ENTRIES-" << endl;
				r_colvar.printlist();		//calls print list function for rides
			}
		}
		else if(menu == 6)
		{
			char pdr;
			cout << "Are you printing a passenger, driver, or ride's information? (enter p/d/r):" << endl;
				cin >> pdr;
			if(pdr == 'p')
			{
				int id;
				cout << "What is your passenger ID?" << endl;
					cin >> id;
				p_colvar.printinfo(id);		//calls print info function for a passenger
			}
			else if(pdr == 'd')
			{
				int id;
				cout << "What is your driver ID?" << endl;
					cin >> id;
				d_colvar.printinfo(id);		//calls print info function for a driver
			}
			else if(pdr == 'r')
			{
				int id;
				cout << "What is your ride ID?" << endl;
					cin >> id;
				r_colvar.printinfo(id);		//calls print info function for a ride
			}
		}
		else if(menu == 7)
		{
			char passordriv;
			cout << "Are you a passenger or driver? (enter p/d):" << endl;
				cin >> passordriv;
			if(passordriv == 'p')
			{
				p_colvar.printrides();		//calls print ride for passenger
			}
			else if (passordriv == 'd')
			{
				d_colvar.printrides();		//calls print ride for driver
			}
		}
		else if(menu == 8)
		{
			cout << "Updating ride progress..." << endl;
			r_colvar.update();		//calls update function
		}
		else if(menu == 9)
		{
			cout << "Cleaning up rides..." << endl;
			r_colvar.cleanup();		//calls cleanup function
		}

	}
	cout << "Before you quit the Mean Green EagleLift System, would you like to save your data? (enter y/n)" << endl;
		char decision;
		cin >> decision;
	if(decision == 'y')
	{
		p_colvar.storepass();		//stores information into the files for the next time it's loaded
		d_colvar.storedrive();
		r_colvar.storeride();
		cout << "Data has been saved. Thank you for using the Mean Green EagleLift System!" << endl;
	}
	else
		cout << "Data not saved. Program exited." << endl;


	return 0;
}
