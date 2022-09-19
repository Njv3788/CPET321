//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Rectangular									
// Description: Complex Numbers : Rectangular		
//			   - Class Definitions					
//			   - Constructor (no parameters)		
//			   - Constructor (with parameters)		
//			   - Operator Overloading for + & -	
//			   - Operator Overloading ==			
//			   - Operator Overloading - & + (unary)	
//			   - Mutator - Sets Magnitude & Angle	
//			   - Assessor - Displays Mag & Angle	
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <cmath>
#include <iomanip>
#include "rectangular.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
using namespace std;

Rectangular::Rectangular()
// constuctors of Rectangular class setting Data Members to 0
{
	real = 0;
	imaginary = 0;
};

Rectangular::Rectangular(double mag, double ang)
// constuctors of Rectangular class setting Data Members
{
	real = mag;
	imaginary = ang;
}


void Rectangular::setRectangularNumber(double mag, double ang)
// Manipulator of Rectangular class setting the Data Members
{
	real = mag;
	imaginary = ang;
}

void Rectangular::displayRectangularNumber()
// Accessor to display the data members in the class
{
	cout << fixed << setprecision(2);
	
	if (imaginary >= 0) {
		cout << setw(6) << real << " + j " << imaginary << endl; 
	}
	else {
		cout << setw(6) << real << " - j " << -imaginary << endl;
	}
};

Rectangular Rectangular::operator+(Rectangular Num)
// Overloading addition to add two complex varibles together 
{
	Rectangular  ans;

	ans.real = real + Num.real;
	ans.imaginary = imaginary + Num.imaginary;

	return ans;
};

Rectangular Rectangular::operator-(Rectangular Num)
// Overloading subtraction to subtract two complex varibles together
{
	Rectangular  ans;

	ans.real = real - Num.real;
	ans.imaginary = imaginary - Num.imaginary;

	return ans;
};

bool Rectangular::operator==(Rectangular Num)
// Overloading equals to test equality for two complex varibles together
{
	double mag_A;
	double mag_B;
	
	mag_A = sqrt(pow(real,2.0) + pow(imaginary, 2));
	mag_B = sqrt(pow(Num.real, 2.0) + pow(Num.imaginary, 2));
	if (mag_A == mag_B) 
		return (true);
	else
		return (false);
};

bool Rectangular::operator>(Rectangular Num)
// Overloading Greater then to find the larger of two complex varibles together
{
	double mag_A;
	double mag_B;

	mag_A = sqrt(pow(real, 2.0) + pow(imaginary, 2));
	mag_B = sqrt(pow(Num.real, 2.0) + pow(Num.imaginary, 2));
	if (mag_A > mag_B) 
		return (true);
	else 
		return (false);
	
};


Rectangular Rectangular::operator+()
// Overloading  unary addition to rotate complex number +90 
{
	
	Rectangular ans;

	if ((abs(real) > 0) && (abs(imaginary) > 0)){
		ans.real = imaginary;
		ans.imaginary = -real;
	}
	else {
		ans.real = real;
		ans.imaginary = imaginary;
	}
	

	return (ans);
};


Rectangular Rectangular::operator-()
// Overloading  unary subtraction to rotate complex number -90 
{
	Rectangular ans;

	if ((abs(real) > 0) && (abs(imaginary)> 0)) {
		ans.real = -imaginary;
		ans.imaginary = real;
	}
	else {
		ans.real = real;
		ans.imaginary = imaginary;
	}

	return (ans);
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++