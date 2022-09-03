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
	ofstream deliverable;

	string filename = "Lab1_deliverable.txt";
	vector<double> alt_value;
	vector<double> polynomial = { -0.12,12.2,-380.5,4100,220 };


	deliverable.open(filename.c_str());
	deliverable << "Hello World!\n" << endl;

	Ballon_Alt(alt_value, polynomial);
	Peak_Valley();

	deliverable.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
