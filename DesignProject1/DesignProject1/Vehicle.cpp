// DesignProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Reservation.h"
#include "vehicle.h" 
#include "player.h"
#include "seat.h"
#include "Rooster.h"

using namespace std;

void Vehicle::generateSeats(int type, list<Seat>& locations)
{
	vector<int> p{ -1,5 };
	vector<int> c{ -1,5,3,3 };
	vector<int> s{ -1,5,2,1,2 };

	switch (type)
	{
	case 0:
		for (int i = 0; i < p.size(); i++)
		{
			locations.push_back(Seat(p.at(i),this->getPointer()));
			postions.push_back(locations.back().getPointer());
		}

		break;
	case 1:
		for (int i = 0; i < c.size(); i++)
		{
			locations.push_back(Seat(c.at(i), this->getPointer()));
			postions.push_back(locations.back().getPointer());
		}
		break;
	case 2:
		for (int i = 0; i < s.size(); i++)
		{
			locations.push_back(Seat(s.at(i), this->getPointer()));
			postions.push_back(locations.back().getPointer());
		}
		break;
	}
}

Vehicle::Vehicle()
{
	vehicleName = "";
	type = -1;
};

Vehicle::Vehicle(string vName, list<Seat>& locations)
{
	int space;
	string temp;
	vehicleName = vName;

	space = vName.find(' ');
	temp = vName.substr(space + 1, vName.size());

	if (temp == "Pickup") { type = 0; }
	else
		if (temp == "Compact") { type = 1; }
		else
			if (temp == "Sudan") { type = 2; }
			else type = -1;

	generateSeats(type, locations);
};

void Vehicle::setPassenger(Player& passenger, int location)
{
	postions.at(location)->setPlayer(passenger);
	passenger.setLocation(postions.at(location));
}

string Vehicle::getVehicleName()
{
	return vehicleName;
};

int Vehicle::getVehicleTypeNum()
{
	return type;
};

vector<Seat*> Vehicle::getSeat()
{
	return postions;
};

Vehicle* Vehicle::getPointer()
{
	return this;
};