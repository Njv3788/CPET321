#ifndef rectangular_Header
#define rectangular_Header

#include <vector>

class Rectangular
{
private:
	double real;
	double imaginary;

public:
	// constuctors of Rectangular class 
	Rectangular();
	Rectangular(double, double);
	
	// Manipulator of Rectangular class
	void setRectangularNumber(double, double);

	// Accessors of Rectangular class
	void displayRectangularNumber();
    
	// Overloading Operators for Addition
	Rectangular operator+(Rectangular);
	Rectangular operator+();
	
	// Overloading Operators for Subtraction 
	Rectangular operator-(Rectangular);
    Rectangular operator-();
	
	// Overloading Operators for  comparsions 
	bool operator==(Rectangular);
	bool operator>(Rectangular);
};
#endif
