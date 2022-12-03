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

using namespace std;

class Player
{
	private:
		string playerName;
		int playerPoint;
	
	public:
		Player()
		{
			playerName = "None";
			playerPoint = 0;
		};

		Player(string player, int points)
		{
			playerName = player;
			playerPoint = points;
		};

		string getName()
		{
			return playerName;
		};

		int getPoints()
		{
			return playerPoint;
		};
}; 
#endif
