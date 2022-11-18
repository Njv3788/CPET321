//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef seat_Header
#define seat_Header

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
};
#endif

