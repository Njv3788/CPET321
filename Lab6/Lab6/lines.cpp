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
{
	a = a_new;
	b = b_new;
	c = c_new;
};

void lineType::displayLine()
{
	cout << fixed << setprecision(2);
};

void lineType::lineSlope()
{
	cout << fixed << setprecision(2);
	double slope;
	
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
{
	double x, y;

	x = (b * second.c - c * second.b) / (a * second.b - b * second.a);
	y = (c * second.a - a * second.c) / (a * second.b - b * second.a);
	
	cout << fixed << setprecision(2);
	cout << "Intersection: ( " << x << " , " << y << " ) ";
	cout << endl;
};

string lineType::findSlope()
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
	{
		if( c != 0 && second.c != 0)
		{ 
			if (this->findSlope() == "horizontal")
			{
				k2 = b / second.b;
				k3 = c / second.c;
				if (k2 == k3)
				{
					equal = true;
				}
				else
				{
					equal = false;
				}
			}
			else if (this->findSlope() == "vertical")
			{
				k1 = a / second.a;
				k3 = c / second.c;
				if (k1 == k3)
				{
					equal = true;
				}
				else
				{
					equal = false;
				}
			}
			else
			{
				k1 = a / second.a;
				k2 = b / second.b;
				k3 = c / second.c;
				if (k1 == k2 == k3)
				{
					equal = true;
				}
				else
				{
					equal = false;
				}
			}
		}
		else
		{
			if (c == second.c)
			{
				k1 = a / second.a;
				k2 = b / second.b;
				if (k1 == k2)
				{
					equal = true;
				}
				else
				{
					equal = false;
				}
			}
			else
			{
				equal = false;
			}
		}
	}

	return equal;
};

bool lineType::operator||(lineType second)
{
	bool parallel = false;

	if (this->findSlope() == second.findSlope())
	{
		parallel = false;
	}

	return parallel;
}

bool lineType::operator&&(lineType second)
{
	bool perp= false;
	
	if ((this->findSlope() == "horizontal")
	   || (second.findSlope() == "horizontal"))
	{
		if ((this->findSlope() == "vertical")
			|| (second.findSlope() == "vertical"))
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
		{
			perp = false;
		}
		else
		{
			if((a/b*second.a/second.b) == 0)
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