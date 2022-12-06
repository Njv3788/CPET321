//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Reservation_Header
#define Reservation_Header

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

Vehicle* select(list<Vehicle*>& container);

Player* select(list<Player>& container);

Player* able2Res(list<Player>& dodgers);

Player* able2Rmv(list<Player>& dodgers);

void reservedSeatViaSeats(list<Seat*>& locations, Player* dodger);

void removeReserved(Player* dodger);

bool changeHow();

#endif

