// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3_ParallelResonant 
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/24/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

#include "ResonantCiruits.h"
#include "ParallelResonant.h"

ParallelResonant::ParallelResonant(double gain, double bandwidth,
	double resonant_freq)
	:ResonantCiruits(gain, bandwidth, resonant_freq) 
//Creates Resonant ciruit -> Parallel Resonant 
//Use the Bandwidth  gain and resonant frquencty to
//Finds the value of the Three compents need 
{
	this->resistor = gain;
	this->capicator = 1 / (bandwidth * this->resistor);
	this->inductor = 1 / (pow(resonant_freq, 2) * this->capicator);
}

void ParallelResonant::display() 
//Display the compent info
//Used Parents Display the Bandwidth, Frequency, gain
{
	cout << "Parallel Resonant Circuit\n" << fixed << setprecision(2);
	cout << "    R" << setfill('.') << setw(8) << " = " << resistor;
	cout << " Ohms \n" << scientific;
	cout << "    C" << setfill('.') << setw(8) << " = ";
	cout << capicator / pow(10, -6) << " uF\n";
	cout << "    L" << setfill('.') << setw(8) << " = ";
	cout << inductor / pow(10, -6) << " mH\n";
	ResonantCiruits::display();
}