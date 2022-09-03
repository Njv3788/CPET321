#include "Lab1_LIB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void Ballon_Alt(vector<double>& alt_value, vector<double> polynomial,double step,double end) {
	
	double alt;
	
	for (double i = 0; i <= (end); i += step) {
		
		alt  = polynomial.at(0) * pow(i, 4) + polynomial.at(1) * pow(i, 3) + polynomial.at(2) * pow(i, 2);
	    alt += polynomial.at(3) * pow(i, 1)+ polynomial.at(4) * pow(i, 0);
		alt_value.push_back(alt);
	}
}

vector<double> Peak_Valley(vector<double> alt_value,double step,double end) {
	
	vector<double> min_max;

	for (int i = 1; i < int(end / step); i++) {
		if (alt_value.at(i) > alt_value.at(i-1)) {
			if (alt_value.at(i) > alt_value.at(i + 1)) {
				cout << "PEAK at " << i*step << endl;
				min_max.push_back(i);
			}
		}
		else {
			if (alt_value.at(i) < alt_value.at(i + 1)) {
				cout << "VALLEY at " << i*step<< endl;
				min_max.push_back(i);
			}
		}
	}

	return(min_max);
}

void outputs(vector<double> alt_value, double step, double end) {
	ofstream deliverable;

	string filename = "Lab1_deliverable.txt";
	deliverable.open(filename.c_str());
	deliverable << "Hello World!\n";
	
	for (int i = 1; i < int(end / step); i++) {
		deliverable << i << "\n";
	}
	deliverable << endl;
	deliverable.close();
}

