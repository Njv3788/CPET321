//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef player_Header
#define player_Header

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "seat.h"

using namespace std;

class Seat;
class Player
{
	private:
		string playerName;
		int playerPoint;
		Seat *loaction;
	
	public:
		Player();

		Player(string player, int points);

		string getName();

		int getPoints();
		
		void setLocation(Seat* postion);
		
		Seat* getLocation();
		
		Player* getPointer();
		
		void takePoints(int amount);

		void addPoints(int amount);

		void removeSeat();
}; 
#endif
