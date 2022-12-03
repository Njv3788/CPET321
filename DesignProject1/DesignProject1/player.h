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
		Player()
		{
			playerName = "None";
			playerPoint = 0;
			loaction = NULL;
		};

		Player(string player, int points)
		{
			playerName = player;
			playerPoint = points;
			loaction = NULL;
		};

		string getName()
		{
			return playerName;
		};

		int getPoints()
		{
			return playerPoint;
		};
		
		void setLocation(Seat & postion)
		{
			loaction = &postion;
		}
}; 
#endif
