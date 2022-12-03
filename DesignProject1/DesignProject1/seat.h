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
		bool reserved;
	    Player *passenger;
	public:
		Seat()
		{
			reserved = false;
			points = 0;
			passenger = new Player();
		};
		Seat(int p)
		{
			if (p < 1)
				reserved = true;
			else
				reserved = false;
			points = p;
			passenger = new Player();
		};

		int getPoints()
		{
			return points;
		}
		bool getReserved()
		{
			return reserved;
		}
		void setPlayer(Player& dodger)
		{
			passenger = &dodger;
		}

		Player* getPlayer()
		{
			return passenger;
		}
};

#endif

