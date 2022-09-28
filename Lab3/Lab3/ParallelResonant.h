// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3_ParallelResonan_Header 
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/24/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef ParallelResonant_Header
#define ParallelResonant_header


#include "ResonantCiruits.h"

using namespace std;

class ParallelResonant : public ResonantCiruits
{
private:
	double resistor;
	double capicator;
	double inductor;
public:
	ParallelResonant(double gain, double bandwidth, double resonant_freq);
	void display();
};

#endif
