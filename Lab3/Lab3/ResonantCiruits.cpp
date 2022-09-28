/// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3_ResonantCircuit 
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
#include "SeriesResonant.h"

using namespace std;
 
ResonantCiruits::ResonantCiruits()
//Creates Resonant ciruit 
//the Bandwidth gain and resonant frquencty are set to 0
{
    bandwidth = 0;
	resonant_freq = 0;
	gain_of_circuit = 0;
}

ResonantCiruits::ResonantCiruits(double gain, double bandwidth,
	                             double resonant_freq) 
//Creates Resonant ciruit 
//Take the Bandwidth  gain and resonant frquencty 
{
	this->bandwidth = bandwidth;
	this->resonant_freq = resonant_freq;;
	this->gain_of_circuit = gain;
}  

void ResonantCiruits::display() 
//Display the Bandwidth, Frequency, gain
{
	cout << setprecision(2) << scientific;
	cout << "    k" << setfill('.') << setw(8) << " = ";
	cout << gain_of_circuit << "\n" << fixed;
	cout << "    beta" << setfill('.') << setw(5) << " = ";
	cout << bandwidth << "\n";
	cout << "    omega" << setfill('.') << setw(4) << " = ";
	cout << resonant_freq << endl;
}

