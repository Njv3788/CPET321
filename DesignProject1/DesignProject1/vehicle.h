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
#include "player.h"

using namespace std;

class Vehicle
{
	private:
		string driverName;
		string vehicleName;
	public:
		Vehicle()
		{
			driverName = "";
			vehicleName = "";
		};

		Vehicle(string dName, string vName)
		{
			driverName = dName;
			vehicleName = vName;
		};

		void displayVehicle()
		{
			cout << "The " << vehicleName << " is driven by " << driverName << endl;
		}

		string getDriverName()
		{
			return driverName;
		};

		string getVehicleName()
		{
			return vehicleName;
		};

};
#endif