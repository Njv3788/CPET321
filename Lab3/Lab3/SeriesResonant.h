// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3_SeriesCircuit_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/24/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef SeriesResonant_Header
#define SeriesResonant_header

#include "ResonantCiruits.h"

using namespace std;

class  SeriesResonant : public ResonantCiruits
{
private:
	double resistor;
	double capicator;
	double inductor;
public:
	SeriesResonant(double gain, double bandwidth, double resonant_freq);
	void display();
};

#endif

