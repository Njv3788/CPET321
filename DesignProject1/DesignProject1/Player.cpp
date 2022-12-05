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

Player::Player()
{
	playerName = "None";
	playerPoint = 0;
	loaction = NULL;
};

Player::Player(string player, int points)
{
	playerName = player;
	playerPoint = points;
	loaction = NULL;
};

string Player::getName()
{
	return playerName;
};

int Player::getPoints()
{
	return playerPoint;
};

void Player::setLocation(Seat* postion)
{
	loaction = postion;
}

Seat* Player::getLocation()
{
	return loaction;
}

Player* Player::getPointer()
{
	return this;
}

void Player::takePoints(int amount)
{
	playerPoint -= amount;
}

void  Player::addPoints(int amount)
{
	playerPoint += amount;
}

void  Player::removeSeat()
{
	loaction = NULL;
}
