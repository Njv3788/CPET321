//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1 
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

#include "Lab1_LIB.h"

using namespace std;

int main()
{
	//declaring variable hard coded variables
	vector<double> polynomial = { -0.12,12.2,-380.5,4100,220 };
	double step = 0.1;            // the smallest interval of time
	double end = 48;              // what time to end 

	//intializing variable that will set throughout the code
	vector<double> alt_value;     // balloon height
	vector<double> min_max;       // Extremes of ride  
	
	Ballon_Alt(alt_value, polynomial, step, end);  // first calculate the path 
	min_max = Peak_Valley(alt_value,step,end);     // second find the extremes
	outputs(alt_value, min_max,step, end);         // Third out put to file
}

