//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "lines.h"
#include "string"

using namespace std;

void lineType::setCoefficient(double a_new, double b_new, double c_new)
//set new varibles to  data members
{
	a = a_new;
	b = b_new;
	c = c_new;
};

void lineType::displayLine()
//dsiplay lines
{
	cout << fixed << setprecision(2); //set postion to 2 and fixed 
	if (b >= 0)
	// if b >= display normally
	{
		cout <<  a <<" x + " << b << " y = " << c;
		cout << endl;
	}
	else
	// diplay - not positive and -b
	{
		cout << a << " x - " << -b << " y = " << c;
		cout << endl;
	}
	
};

void lineType::lineSlope()
//finds and displays slope
{
	cout << fixed << setprecision(2);  //set postion to 2 and fixed
	
	if (a == 0)        
	{
		cout << "slope: horizontal";
	}
	else if (b == 0)
	{
		cout << "slope: vertical";
	}
	else
	{
		cout << "slope: " << - (a / b);
	}
	cout << endl;
};

void lineType::Intersection(lineType second)
// finds intersection and display interction
{
	double x, y;

	x = (b * second.c - c * second.b) / (a * second.b - b * second.a);
	y = (c * second.a - a * second.c) / (a * second.b - b * second.a);
	
	cout << fixed << setprecision(2);   //set postion to 2 and fixed
	cout << "Intersection: ( " << x << " , " << y << " ) ";
	cout << endl;
};

string lineType::findSlope()
// helper functionfinds slope and puts it in a string
{
	string slope;

	if (a == 0)
	{
		slope = "horizontal";
	}
	else if (b == 0)
	{
		slope = "vertical";
	}
	else
	{
		slope = to_string( -(a / b));
	}
	
	return slope;
};



bool lineType::operator==(lineType second) 
{
	bool equal = false;
	double k1, k2, k3;

	if (this->findSlope() == second.findSlope())
	// continue if slopes are equal
	{
		if( c != 0 && second.c != 0)
		// if c or second.c are not zero
		{ 
			if (this->findSlope() == "horizontal")
			// horizontal chack ratios of b and c
			{
				k2 = b / second.b;
				k3 = c / second.c;
				if (k2 == k3)
				//if ratios are equal
				{
					equal = true;
				}
			}
			else if (this->findSlope() == "vertical")
			// vertical chack ratios of a and c
			{
				k1 = a / second.a;
				k3 = c / second.c;
				if (k1 == k3)
				//if ratios are equal
				{
					equal = true;
				}
			}
			else
			// check raitos
			{
				k1 = a / second.a;
				k2 = b / second.b;
				k3 = c / second.c;
				if ((k1 == k2) && (k1 == k3))
				//if all ratios are equal 
				{
					equal = true;
				}
			}
		}
		else
		{
			if (c == second.c)
			//if c and second.c
			{
				k1 = a / second.a;
				k2 = b / second.b;
				if (k1 == k2)
				//if ratios are equal
				{
					equal = true;
				}
			}
		}
	}

	return equal;
};

bool lineType::operator||(lineType second)
// checks if lines are parallel
{
	bool parallel = false;

	if (this->findSlope() == second.findSlope())
	//checks if lines slopes are parallel
	{
		parallel = true;
	}

	return parallel;
}

bool lineType::operator&&(lineType second)
// checks if lines are parallel,perpendicular
{
	bool perp= false;
	
	if ((this->findSlope() == "horizontal")
	   || (second.findSlope() == "horizontal"))
	// checks to see if a line is "horizontal"
	{
		if ((this->findSlope() == "vertical")
			|| (second.findSlope() == "vertical"))
		// checks to see if a line is "vertical"
		{
			perp = true;
		}
		else
		{
			perp = false;
		}
	}
	else
	{
		if ((this->findSlope() == "vertical")
			|| (second.findSlope() == "vertical"))
		// checks to see if a line is "vertical"
		{
			perp = false;
		}
		else
		{
			if((a/b*second.a/second.b) == 1)
			// checks to see if slopes are multipled together are 1
			{
				perp = true;
			}
			else
			{
				perp = false;
			}
		}
	}
	return perp;
}