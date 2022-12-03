// DesignProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Reservation.h"
#include "vehicle.h" 
#include "player.h"

using namespace std;

int  mainMenu()
{
    int choose;

    cout << "Choose what waht yoyu want to do" << endl;
    cout << "(1)  : Display Dodger Rooster" << endl;
    cout << "(2)  : Display Seat Rooster" << endl;
    cout << "(3)  : Display Vehicle Rooster" << endl;
    cout << "(-1) : Quit" << endl;
    cin >> choose;

    return choose;
}

int main()
{
    
    list<Vehicle> cars;
    list<Player> dodgers;
    int choose = -1;

    readInPlayer(cars,dodgers);
    cout << "Welcome Dodgers to Your Reservation Systems" << endl;

    do
    {   system("pause");
        system("cls");

        choose = mainMenu();

        switch (choose)
        {
            case 1:
                playerRooster(dodgers);
                break;
            case 2: 
                seatRooster(cars);
                break;
            case 3:
                vehicleRooster(cars);
                break;
            default:
                break;
        }
        
    } while (choose != -1);
   
    return 0;
}

