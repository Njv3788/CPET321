//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Lab1_LIB_Header
#define Lab1_LIB_header

#include <vector>

using namespace std;

void Ballon_Alt(vector<double>& alt_value, vector<double> polynomial,double step,double end);
vector<double> Peak_Valley(vector<double>,double,double);
void outputs(vector<double> alt_value, vector<double> min_max, double step, double end);

#endif