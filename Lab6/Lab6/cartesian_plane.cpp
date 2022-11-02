//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "lines.h"

#define NUM_OF_LINES 4
using namespace std;


int main() {
	bool quit = false;
	float a, b, c;
	int choise;
	int line_select_1, line_select_2;
	vector<lineType> myLines(NUM_OF_LINES);

	do
	//run through Once 
	//continue to run until condition not meet
	//clear and pause after each run
	{
		system("pause");                         
		system("cls");
		
		//display the menu for the program 
		cout << "Select which you would like to do:" << endl;
		cout << "1) Set" << endl;
		cout << "2) Display Line" << endl;
		cout << "3) Display ALL Lines" << endl;
		cout << "4) Slope" << endl;
		cout << "5) Equal" << endl;
		cout << "6) Parallel" << endl;
		cout << "7) Perpendicular" << endl;
		cout << "8) Intersection" << endl;
		cout << "9) Quit" << endl;

		cin >> choise; //input the operation that the use wants done
		switch (choise) 
		{
			case 0: // debug mode
					myLines.at(0).setCoefficient(10, 20, 30);
					myLines.at(1).setCoefficient(10, 20, 30);
					myLines.at(2).setCoefficient(20, 40, 60);
					myLines.at(3).setCoefficient(5, 10, 15);
					break;
			case 1: // set the coefficints for line then display line
					cout << "which line would you like to work with: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;

					cout << "please type in the value:" << endl;
					cout << "a = "; cin >> a;
					cout << "b = "; cin >> b;
					cout << "c = "; cin >> c;
					myLines.at(line_select_1).setCoefficient(a, b, c);
					myLines.at(line_select_1).displayLine();
					break;
			case 2: // display the chosen line
					cout << "which line would you like to displa: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;
					myLines.at(line_select_1).displayLine();
					break;
			case 3: // display ALL lines
					for (int i = 0; i < NUM_OF_LINES; i++)
						myLines.at(i).displayLine();
					break;
			case 4: // display the chosen lines and its line slope
					cout << "which line would you like to work with: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;
					myLines.at(line_select_1).displayLine();
					myLines.at(line_select_1).lineSlope();
					break;
			case 5: // display the chosen lines and if they are equal
					cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;
					myLines.at(line_select_1).displayLine();
					cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_2;
					myLines.at(line_select_2).displayLine();
					if (myLines.at(line_select_1) == myLines.at(line_select_2)) {
						cout << "these two lines are EQUAL" << endl;
					}
					else {
						cout << "these two lines are NOT EQUAL" << endl;
					}
					break;
			case 6:  // display the chosen lines and if they are parallel
					cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;
					myLines.at(line_select_1).displayLine();

					cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_2;
					myLines.at(line_select_2).displayLine();

					if (myLines.at(line_select_1) || myLines.at(line_select_2)) {
						cout << "these two lines are PARALLEL" << endl;
					}
					else {
						cout << "these two lines are NOT PARALLEL" << endl;
					}
					break;
			case 7: // display the chosen lines and if they are perpendicular
					cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;
					myLines.at(line_select_1).displayLine();

					cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_2;
					myLines.at(line_select_2).displayLine();

					if (myLines.at(line_select_1) && myLines.at(line_select_2)) {
						cout << "these two lines are PERPENDICULAR" << endl;
					}
					else {
						cout << "these two lines are NOT PERPENDICULAR" << endl;
					}
					break;
			case 8: // display the chosen lines and their intersection
					cout << "select the first line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_1;
					myLines.at(line_select_1).displayLine();

					cout << "select the second line: [0.." << NUM_OF_LINES - 1 << "]" << endl;
					cin >> line_select_2;
					myLines.at(line_select_2).displayLine();
					myLines.at(line_select_1).Intersection(myLines.at(line_select_2));
					break;
			case 9: //quit
					quit = true;
					break;
		}
	} while (!quit);

	return 0;
}
