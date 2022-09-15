/**********************************************************/
/*** Title: Polar_6.cpp									***/
/*** Description: Complex Numbers : Polar				***/
/***				- Class Definitions					***/
/***				- Constructor (no parameters)		***/
/***				- Constructor (with parameters)		***/
/***				- Operator Overloading for * & /	***/
/***				- Operator Overloading for + & -	***/
/***				- Operator Overloading ==			***/
/***				- Operator Overloading - (unary)	***/
/***				- Mutator - Sets Magnitude & Angle	***/
/***				- Assessor - Displays Mag & Angle	***/
/**********************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "rectangular.h"

using namespace std;

Rectangular::Rectangular()
{
	real = 0;
	imaginary = 0;
};

Rectangular::Rectangular(double mag, double ang)
{
	real = mag;
	imaginary = ang;
}


void Rectangular::setRectangularNumber(double mag, double ang)
{
	real = mag;
	imaginary = ang;
}

void Rectangular::displayRectangularNumber()
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
{
	Rectangular  ans;

	ans.real = real + Num.real;
	ans.imaginary = imaginary + Num.imaginary;

	return ans;
};

Rectangular Rectangular::operator-(Rectangular Num)
{
	Rectangular  ans;

	ans.real = real - Num.real;
	ans.imaginary = imaginary - Num.imaginary;

	return ans;
};

bool Rectangular::operator==(Rectangular Num)
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
{
	const float PI = 3.14159;
	Rectangular ans;
	
	double mag;
	double theta;

	mag = sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
    theta = atan2(real, imaginary) * (180.0 / PI);

	theta += 45;
	
	ans.real = mag * cos(theta * (PI / 180.0));
    ans.imaginary = mag * sin(theta * (PI / 180.0));

	return (ans);
};


Rectangular Rectangular::operator-()
{
	const float PI = 3.14159;
	Rectangular ans;

	double mag;
	double theta;

	mag = sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
	theta = atan2(real, imaginary) * (180.0 / PI);

	theta -= 45;

	ans.real = mag * cos(theta * (PI / 180.0));
	ans.imaginary = mag * sin(theta * (PI / 180.0));

	return (ans);
};


//*******************************************