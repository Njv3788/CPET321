//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef vehicle_Header
#define vehicle_Header

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "seat.h"
#include "player.h"
#include "Reservation.h"

using namespace std;

class Seats;
class Vehicle
{   
	private:
		string vehicleName;
		int type;
		vector<Seat*> postions;
		
		void generateSeats(int type, list<Seat>& locations);

	public:
		Vehicle();

		Vehicle(string vName, list<Seat>& locations);

		void setPassenger(Player& passenger, int location);

		string getVehicleName();

		int getVehicleTypeNum();

		vector<Seat*> getSeat();

		Vehicle* getPointer();
		
		friend Vehicle* Seat::getVehicle();
};


#endif