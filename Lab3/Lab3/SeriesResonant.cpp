// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3_SeriesResonant 
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
#include "SeriesResonant.h"
SeriesResonant::SeriesResonant(double gain, double bandwidth,
	                           double resonant_freq)
	           :ResonantCiruits(gain, bandwidth, resonant_freq) 
//Creates Resonant ciruit -> series Resonant 
//Use the Bandwidth  gain and resonant frquencty to
//Finds the value of the Three compents need  
{
	this->resistor = 1 / gain;
	this->inductor = this->resistor / bandwidth;
	this->capicator = 1 / (pow(resonant_freq, 2) * this->inductor);
}
void SeriesResonant::display() 
//Display the compent info
//Used Parents Display the Bandwidth, Frequency, gain
{
	cout << "Series Resonant Circuit\n" << fixed << setprecision(2);
	cout << "    R" << setfill('.') << setw(8) << " = " << resistor;
	cout << " Ohms \n" << scientific;
	cout << "    C" << setfill('.') << setw(8) << " = " << capicator / pow(10, -6);
	cout << " uF\n";
	cout << "    L" << setfill('.') << setw(8) << " = " << inductor / pow(10, -3);
	cout << " mH\n";
	ResonantCiruits::display();
};