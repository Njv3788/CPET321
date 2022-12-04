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
    cout << "(1)  : View Dodger Rooster" << endl;
    cout << "(2)  : View Seat Assignment" << endl;
    cout << "(3)  : Make a Reveration  By Choosing a Car" << endl;
    cout << "(4)  : Make a Reveration  By Choosing a Seat" << endl;
    cout << "(5)  : Remove a Reservation" << endl;
    cout << "(-1) : Quit" << endl;
    cin >> choose;

    return choose;
}

int main()
{
    
    list<Vehicle> cars;
    list<Player> dodgers;
    vector<Seat*> location;
    int choose = -1;
    bool able;
    Player* user;

    readInPlayer(cars,dodgers);
    location = generatorListOfSeats(cars);

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
                playerRooster(dodgers);
                user = able2Res(dodgers); system("cls");
                if (user != NULL)
                {
                    vehicleRooster(cars);
                }
                break;
            case 4:
                playerRooster(dodgers);
                user= able2Res(dodgers); system("cls");
                if (user != NULL)
                {

                }
                break;
            case 5:
                playerRooster(dodgers);
                user = able2Rmv(dodgers); system("cls");
                break;
            default:
                break;
        }
        
    } while (choose != -1);
   
    return 0;
}

