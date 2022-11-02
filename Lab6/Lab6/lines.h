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
//class of lines of the form ax+by=c
//stores a,b,c uses the fine slope and 
//if two lines equal, parallel, perpendicular
//and the intersection
{

	private:

		double a;
		double b;
		double c;

		//helper function
		string findSlope();

	public:
	
		lineType()
		//constuctor that set every thing to 1
		{
			a = 1;
			b = 1;
			c = 1;
		};
		
		// manipultors
		void setCoefficient(double, double, double);  //allows for settimng coefficints
		
		// assecors to
		void displayLine();                           //display line
		void lineSlope();                             //find and display slope
		void Intersection(lineType);                  //find and display intersection with second line
		
		//overloaded operators
		bool operator==(lineType);                    //determine if two lines are equal
		bool operator||(lineType);                    //determine if two lines are parallel
		bool operator&&(lineType);					  //determine if two lines are perpendicular

};

#endif