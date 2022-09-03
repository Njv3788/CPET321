// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

#include "Lab1_LIB.h"

using namespace std;



int main()
{
	
	vector<double> alt_value;
	vector<double> polynomial = { -0.12,12.2,-380.5,4100,220 };
	double step = 0.1;
	double end = 48;
	Ballon_Alt(alt_value, polynomial,step,end);
	Peak_Valley(alt_value,step,end);
	outputs(alt_value, step, end);
}

