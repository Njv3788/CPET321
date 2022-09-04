//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library 
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Lab1_LIB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void Ballon_Alt(vector<double>& alt_value, vector<double> polynomial,
				double step,double end) {
// In this function the vector of balloon altitudes is brought through 
// Pass by reference,Then Calculates the height using the polynomial 0 
// is coeffictent of largest term, then Loads the Height of the balloons 
// and then leaves
	double alt;
	
	for (int i = 0; i <= int(end/step); i++) {
	// looping by using fixed point 
		alt  = polynomial.at(0) * pow(i * step, 4);
		alt += polynomial.at(1) * pow(i * step, 3);
		alt += polynomial.at(2) * pow(i * step, 2);
		alt += polynomial.at(3) * pow(i * step, 1);
		alt += polynomial.at(4) * pow(i * step, 0);
		alt_value.push_back(alt);
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
vector<double> Peak_Valley(vector<double> alt_value,double step,double end) {
// In this function the ballons path is brought in 
// Then is put in a loop exluding the end points 
// Compare values to the left and right to fin maximum 
	vector<double> min_max;

	for (int i = 1; i < int(end / step); i++) {
	// looping by using fixed point excluding end points 
		if (alt_value.at(i) > alt_value.at(i-1)) {
		//Is the balloon heigher then it was
			if (alt_value.at(i) > alt_value.at(i + 1)) {
			// is the balloon higher then it will higher
				min_max.push_back(i);
			}
		}
		else {
			if (alt_value.at(i) < alt_value.at(i + 1)) {
			//Is the balloon lower then it will 
				min_max.push_back(i);
			}
		}
	}

	
	return(min_max);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void outputs(vector<double> alt_value, vector<double> min_max,  double step, 
			double end) {
// In this function open a file is opened 
// writes the extremes of thepath to the file   
// then write the overall path of to file and closes it 
	ofstream deliverable;

	string filename = "Lab1_deliverable.txt";
	deliverable.open(filename);               //opens File
	deliverable << setprecision(2)<<fixed;    //formats this bitch 
	
	//Output  the extremes 
	deliverable <<"Extremes:" <<setw(9)<< "Time" << setw(10) << "Height\n";
	for (int i = 0; i < min_max.size(); i++) {
	//Loops through fixed point
		deliverable << setw(18)<< min_max.at(i) * step;
		deliverable << setw(9) << alt_value.at(min_max.at(i)) << "\n";
	}
	
	//Outputs the overall path 
	deliverable << "Overall path:"<< setw(5) << "Time"<< setw(10) << "Height\n";
	for (int i = 0; i <= int(end / step); i++) {
	//Loops through fixed point
		deliverable << setw(18) << i*step << setw(9)<< alt_value.at(i) << "\n";
	}

	deliverable << endl;      //end line
	deliverable.close();      //closes file
}

