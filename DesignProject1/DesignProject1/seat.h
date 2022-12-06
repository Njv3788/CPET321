//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef seat_Header
#define seat_Header


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "player.h"
#include "vehicle.h" 

using namespace std;

class Player;

class Vehicle;

class Seat
{
	private:
		int points;
	    Player *passenger;
		Vehicle* car;
	public:
		Seat();

		Seat(int p);

		Seat(int p, Vehicle* fuck);

		int getPoints();

		bool getReserved();

		void setPlayer(Player& dodger);

		void removePlayer();

		Player* getPlayer();

		Seat* getPointer();

		Vehicle* getVehicle();

		void setVehicle(Vehicle* Automotive);
};

#endif

