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

using namespace std;

class Seat
{
	private:
		int points;
		bool reserved;
	public:
		Seat()
		{
			reserved = false;
			points = 0;
		};
		Seat(int p)
		{
			reserved = false;
			points = p;
		};

		void display()
		{
			if (points == 0) 
			{
				cout << "   ";
			}
			else if (points == -1)
			{
				cout << "(D)";
			}
			else if (reserved == false)
			{
				cout << "(" << points << ")";
			}
			else
				cout << "(X)";
		};
};
#endif

