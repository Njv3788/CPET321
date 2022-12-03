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
#include <iomanip>
#include <string>
#include <list>
#include "seat.h"
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
            cars.push_back(Vehicle(temp));
            dodgers.push_back(Player(name, -1));
            cars.back().setPassenger(dodgers.back(),0);
        }
        else
        {
            dodgers.push_back(Player(name, stoi(temp)));
        }


    } while (!(inFile.eof()));
    return;
};

void seatRooster(list<Vehicle> cars)
{
    vector<Seat> postions;
    int points;
    bool reserved;

    cout << setw(15) << left << "Vehicle" << "|";
    cout << setw(15) << "Type of seat" << "|";
    cout << setw(6)  << "Points" << "|";
    cout << setw(15) << "Resevation Status" << "|";
    cout << setw(15) << "Dodger " << endl;
    cout << setfill('-') << setw(60) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : cars)
    {
        postions = it.getSeat();
        
        for(auto loop : postions)
        { 
            cout << setw(15) << left << it.getVehicleName() << "|";
            points = loop.getPoints();

            switch (points)
            {
                case -1:
                    cout << setw(15) << "Driver" << "|" ;
                    cout << setw(6)  << right << "N/A" << "|";
                    break;
                case  1:
                    cout << setw(15) << "Center Back" << "|";
                    cout << setw(6) << right << points << "|";
                    break;
                case  2:
                    cout << setw(15) << "Side Back" << "|" ;
                    cout << setw(6) << right << points << "|";
                    break;
                case  3:
                    cout << setw(15) << "Compact Back" << "|" ;
                    cout << setw(6) << right << points << "|";
                    break;
                case  5:
                    cout << setw(15) << "Passenger" << "|" ;
                    cout << setw(6) << right << points << "|";
                    break;
            }
            reserved = loop.getReserved();
            if (reserved)
                cout << right << setw(17) << "Resereved" << "|";
            else
                cout << right << setw(17) << "Open" << "|";
            cout << setw(15) << loop.getPlayer()->getName()<< endl;
        }
    }

};

void vehicleRooster(list<Vehicle> cars)
{
    bool status;
    vector<Seat> postions;

    cout << setw(15) << left << "Vehicle" << "|";
    cout << setw(15) << left << "Driver" << "|";
    cout << setw(17) << "Resevation Status" << endl;
    cout << setfill('-') << setw(50) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : cars)
    {
        status = true;
        cout << setw(15) << left << it.getVehicleName() << "|";
        postions = it.getSeat();

        cout << setw(15) << it.getSeat().at(0).getPlayer()->getName() << "|";
        
        for (auto loop : postions)
        {
            if (!loop.getReserved()) 
            {
                status = false;
            }
        }

        if(status)
            cout << right << setw(17) << "Full" << endl;
        else
            cout << right << setw(17) << "Seats Available" << endl;
    }
}

void playerRooster(list<Player> dodgers)
{
    cout << setw(20) << left << "Dodger" << "|";
    cout << setw(7) <<  "Points" << endl;
    cout << setfill('-') << setw(30) << right << ' ' << endl;
    cout << setfill(' ');
    
    for (auto it : dodgers)
    {
        cout << setw(20) << left << it.getName() <<  "|";
        if(-1 == it.getPoints())
            cout << setw(5) << right << "n/a" << endl;
        else
            cout << setw(5) << right << it.getPoints() << endl;
    }
   
}

void generatorListOfSeats(list<Vehicle>& cars, list<Seat*> & location)
{
    for (auto it : cars)
    {

        for (auto loop : postions)
        {
            location.push_back(*loop);
        }
    }
}
#endif

