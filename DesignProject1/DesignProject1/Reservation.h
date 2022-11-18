//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Reservation_Header
#define Reservation_Header

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "vehicle.h" 
#include "player.h"

using namespace std;

void readInPlayer(list<Vehicle>& cars, list<Player>& dodgers)
{
    ifstream inFile;
    string name, temp;

    inFile.open("dodgeball.txt");

    if (!inFile.is_open())
        // if not open return to main 
    {
        cout << "File unable to be found or is bad" << endl;
        return;
    }

    do  //loop till end of file
    {
        name = "";
        for (int i = 0; i < 2; i++)
        {
            inFile >> temp;
            name += temp + " ";
        }
        name.pop_back();

        getline(inFile, temp);
        temp = temp.substr(1, (temp.length() - 1));

        if (!(isdigit(temp.front())))
        {
            cars.push_back(Vehicle(name, temp));
            dodgers.push_back(Player(name, -1));
        }
        else
        {
            dodgers.push_back(Player(name, stoi(temp)));
        }
    

    } while (!(inFile.eof()));
    return;
}



#endif

