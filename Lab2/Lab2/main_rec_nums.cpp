
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_2 (main_rec_nums.cpp)
// Description: Complex Numbers : Rectangular			
// Course : Computational problem soving II
// Developer: Dr George Zion
// Student : Nathaniel Valla 
// Date :9/17/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include "rectangular.h"

using namespace std;

int main()
{
	//***************************************************************//
	// This section test the following member functions
	// 		Rectangular()
	//		Rectangular(double, double)
	//		void setRectangularNumber(double, double)
	//		void displayRectangularNumber()
	//***************************************************************//
	int testNumber;

	cin >> testNumber;


	Rectangular A(3.0, 4.0), B(4.0, 5.0), C, D, E, Ans1, Ans2;

	C.setRectangularNumber(-3.0, -4.0);
	D.setRectangularNumber(8.0, -8.0);

	switch (testNumber)
	{
	case 1: //***************************************************************//
			 // Section #1:
			 // This section test the following member function
			 //		Rectangular displayRectangular()
			 //***************************************************************//
		cout << "Section #1 Test:" << endl;
		cout << "  (A) ";	A.displayRectangularNumber();
		cout << "  (B) ";	B.displayRectangularNumber();
		cout << "  (C) ";	C.displayRectangularNumber();
		cout << "  (D) ";	D.displayRectangularNumber();
		break;

	case 2: //***************************************************************//
			 // Section #2:
			 // This section test the following member functions
			 //		Rectangular operator + (Rectangular)
			 //		Rectangular operator - (Rectangular)
			 //***************************************************************//
		cout << "Section #2 Test:" << endl;
		Ans1 = A + B;
		cout << "  A + B = "; Ans1.displayRectangularNumber();
		Ans1 = A - B;
		cout << "  A - B = "; Ans1.displayRectangularNumber();

		Ans1 = A + C;
		cout << "  A + C = "; Ans1.displayRectangularNumber();
		Ans1 = A - C;
		cout << "  A - C = "; Ans1.displayRectangularNumber();

		Ans1 = C + D;
		cout << "  C + D = "; Ans1.displayRectangularNumber();
		Ans1 = C - D;
		cout << "  C - D = "; Ans1.displayRectangularNumber();

		Ans1 = A + B - C + D;
		cout << "  A + B - C + D = "; Ans1.displayRectangularNumber();
		Ans1 = (A + B) - (C + D);
		cout << "  (A + B) - (C + D) = "; Ans1.displayRectangularNumber();
		break;

	case 3: //***************************************************************//
			 // Section #3:
			 // This section test the following member functions
			 //		bool operator == (Rectangular)
			 //		bool operator >  (Rectangular)
			 //		bool operator >= (Rectangular)
			 //***************************************************************//
		cout << "Section #3 Test:" << endl;
		A.setRectangularNumber(3.0, 4.0);
		B.setRectangularNumber(3.0, 4.0);
		cout << "  (A) ";	A.displayRectangularNumber();
		cout << "  (B) ";	B.displayRectangularNumber();
		if (A > B)
			cout << "   A is greater-than B" << endl;
		else if (A == B)
			cout << "   A is equal-to B" << endl;
		else
			cout << "   A is less-than B" << endl;

		C.setRectangularNumber(1.0, 0.0);
		B = B + C;
		cout << "  (A) ";	A.displayRectangularNumber();
		cout << "  (B) ";	B.displayRectangularNumber();
		if (A > B)
			cout << "   A is greater-than B" << endl;
		else if (A == B)
			cout << "   A is equal-to B" << endl;
		else
			cout << "   A is less-than B" << endl;

		C.setRectangularNumber(0.0, -1.0);
		B = B + C;
		cout << "  (A) ";	A.displayRectangularNumber();
		cout << "  (B) ";	B.displayRectangularNumber();
		if (A > B)
			cout << "   A is greater-than B" << endl;
		else if (A == B)
			cout << "   A is equal-to B" << endl;
		else
			cout << "   A is less-than B" << endl;

		C.setRectangularNumber(-1.0, 0.0);
		B = B + C;
		cout << "  (A) ";	A.displayRectangularNumber();
		cout << "  (B) ";	B.displayRectangularNumber();
		if (A > B)
			cout << "   A is greater-than B" << endl;
		else if (A == B)
			cout << "   A is equal-to B" << endl;
		else
			cout << "   A is less-than B" << endl;
		break;
	case 4: //***************************************************************//
			 // Section #4:
			 // This section test the following member functions
			 //		Rectangular operator+()
			 //***************************************************************//
		cout << "Section #4 Test:" << endl;
		cout << " Rotate Clock-Wise" << endl;
		// 1st Quad
		A.setRectangularNumber(8.0, 12.0);
		cout << "  (A) ";	A.displayRectangularNumber();
		// 1st -> 4th Quad
		B = +A;
		cout << "  (B) ";	B.displayRectangularNumber();
		// 4th -> 3rd Quad
		C = +B;
		cout << "  (C) ";	C.displayRectangularNumber();
		// 3rd -> 2nd Quad
		D = +C;
		cout << "  (D) ";	D.displayRectangularNumber();
		// 2nd -> 1st Quad
		E = +D;
		cout << "  (E) ";	E.displayRectangularNumber();
		cout << endl;
		break;

	case 5: //***************************************************************//
			 // Section #5:
			 // This section test the following member functions
			 //		Rectangular operator-()
			 //***************************************************************//
		cout << "Section #5 Test:" << endl;
		cout << " Rotate Counter Clock-Wise" << endl;
		// 1st Quad
		A.setRectangularNumber(8.0, 12.0);
		cout << "  (A) ";	A.displayRectangularNumber();
		// 1st -> 2nd
		B = -A;
		cout << "  (B) ";	B.displayRectangularNumber();
		// 2nd -> 3rd
		C = -B;
		cout << "  (C) ";	C.displayRectangularNumber();
		// 3rd -> 4th
		D = -C;
		cout << "  (D) ";	D.displayRectangularNumber();
		// 4th -> 1st
		E = -D;
		cout << "  (E) ";	E.displayRectangularNumber();
		cout << endl;
		break;
	}
	return 0;
}
/**********************************************************/