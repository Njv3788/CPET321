//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef seat_Rooster
#define seat_Rooster 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <set>
#include "seat.h"
#include "vehicle.h" 
#include "player.h"

using namespace std;



void readInPlayer(list<Vehicle*>& cars, list<Player>& dodgers, list<Seat*>& locations);

void seatRooster(list<Seat*>& location);

void vehicleRooster(list<Vehicle*>& cars);

void playerRooster(list<Player>& dodgers);

void printRooster(list<Player>& dodgers);

void printRooster(list<Vehicle*>& cars);

void printRooster(Vehicle* car);


#endif