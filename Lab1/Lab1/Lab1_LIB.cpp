#include "Lab1_LIB.h"
#include <iostream>
#include <vector>

using namespace std;

void Ballon_Alt(vector<double> alt_value, vector<double> polynomial) {

	for (float i = 0; i < 49; i += 1) {
		cout << i << endl;
		alt_value.push_back(i);
	}
}

void Peak_Valley() {

	cout << "don't Worry This is a prototype" << endl;
}
