
#ifndef Lab1_LIB_Header
#define Lab1_LIB_header

#include <vector>

using namespace std;

void Ballon_Alt(vector<double>& alt_value, vector<double> polynomial,double step,double end);
vector<double> Peak_Valley(vector<double>,double,double);
void outputs(vector<double> alt_value, double step, double end);

#endif