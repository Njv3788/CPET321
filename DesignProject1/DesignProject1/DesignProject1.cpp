// DesignProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Reservation.h"
#include "vehicle.h" 
#include "player.h"

using namespace std;

int main()
{
    
    list<Vehicle> cars;
    list<Player> dodgers;

    readInPlayer(cars,dodgers);
    
    for (auto it : cars)
    {
        it.displayVehicle();
    }

    return 0;
}

