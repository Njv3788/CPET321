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

using namespace std;

class Player;
class Seat
{
	private:
		int points;
	    Player *passenger;
	public:
		Seat()
		{
			points = 0;
			passenger = NULL;
		};
		Seat(int p)
		{
			points = p;
			passenger = NULL;
		};

		int getPoints()
		{
			return points;
		}
		bool getReserved()
		{
			return passenger != NULL;
		}
		void setPlayer(Player& dodger)
		{
			passenger = &dodger;
		}
		void removePlayer()
		{
			passenger = NULL;
		}

		Player* getPlayer()
		{
			return passenger;
		}
		Seat* getPointer()
		{
			return this;
		}
};

#endif

