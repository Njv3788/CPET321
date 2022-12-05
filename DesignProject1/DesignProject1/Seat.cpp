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

Seat::Seat()
{
	points = 0;
	passenger = NULL;
	car = NULL;
};

Seat::Seat(int p, Vehicle* automotive)
{
	points = p;
	passenger = NULL;
	car = automotive;
};

int Seat::getPoints()
{
	return points;
}

bool Seat::getReserved()
{
	return passenger != NULL;
}

void Seat::setPlayer(Player& dodger)
{
	passenger = &dodger;
}

void Seat::removePlayer()
{
	passenger = NULL;
}

Player* Seat::getPlayer()
{
	return passenger;
}

Seat* Seat::getPointer()
{
	return this;
}

Vehicle* Seat::getVehicle()
{
	return car;
};