//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef lines_Header
#define lines_Header

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "lines.h"

using namespace std;

class lineType
{

	private:

		double a;
		double b;
		double c;

	public:
	
		lineType()
		{
			a = 1;
			b = 1;
			c = 1;
		};

		void setCoefficient(double, double, double);
		void displayLine();
		void lineSlope();
		void Intersection(lineType);
		
		string findSlope();
		
		bool operator==(lineType);
		bool operator||(lineType);
		bool operator&&(lineType);

};

#endif