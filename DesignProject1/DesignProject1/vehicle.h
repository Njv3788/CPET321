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
#include "player.h"
#include "seat.h"
#include "Reservation.h"

using namespace std;

struct Occupied;

class Vehicle
{   
	private:
		string driverName;
		string vehicleName;
		int type;
		vector<Seat> postions;
		
		void generateSeats(int type)
		{
			vector<int> p { -1,5 };
			vector<int> c { -1,5,3,3};
			vector<int> s { -1,5,2,1,2};

			switch (type)
			{
				case 0:
					for (int i = 0; i < p.size(); i++)
						postions.push_back(Seat(p.at(i)));
					break;
				case 1:
					for (int i = 0; i < c.size(); i++)
						postions.push_back(Seat(c.at(i)));
					break;
				case 2:
					for (int i = 0; i < s.size(); i++)
						postions.push_back(Seat(s.at(i)));
					break;
				default:
						postions.push_back(Seat(-1));
						break;
			}
		}

	public:
		Vehicle()
		{
			driverName = "";
			vehicleName = "";
			type = -1;
			generateSeats(-1);
			
			cout << endl;
		};

		Vehicle(string dName, string vName)
		{
			int space;
			string temp;
			driverName = dName;
			vehicleName = vName;
			
			space = vName.find(' ');
			temp = vName.substr(space+1, vName.size());

			if(temp == "Pickup"){ type = 0; }
			else 
				if (temp == "Compact"){ type = 1; }
				else 
					if (temp == "Sudan"){ type = 2; }
					else type = -1;
			
			generateSeats(type);
		};

		string getDriverName()
		{
			return driverName;
		};

		string getVehicleName()
		{
			return vehicleName;
		};

		int getVehicleTypeNum()
		{
			return type;
		};

		Seat getSeat(int location)
		{
			return postions.at(location);
		};

		vector<Seat> getSeat()
		{
			return postions;
		};
};


#endif