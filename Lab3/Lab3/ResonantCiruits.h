// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_3_ResonantCircui_Header 
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/24/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef ResonantCiruits_Header
#define ResonantCiruits_Header

using namespace std;

class ResonantCiruits
{
	protected:
		double bandwidth;
		double resonant_freq;
		double gain_of_circuit;
	public:
		ResonantCiruits();
		ResonantCiruits(double gain, double bandwidth, double resonant_freq);
		void display();
};

#endif
