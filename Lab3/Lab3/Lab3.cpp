// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3 Main 
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/24/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

#include "ResonantCiruits.h"
#include "ParallelResonant.h"
#include "SeriesResonant.h"

using namespace std;

int main()
{
	SeriesResonant  SRC1(0.0025, 12345, 120000);
	ParallelResonant PRC1(120, 65321, 450000);

	SRC1.display();
	PRC1.display();

	return(0);
}