// DesignProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Reservation.h"
#include "vehicle.h" 
#include "player.h"
#include "seat.h"
#include "Rooster.h"

using namespace std;

int  mainMenu()
{
    int choose;

    cout << "Choose what you want to do" << endl;
    cout << "(1)  : View Dodger Rooster" << endl;
    cout << "(2)  : View Seat Assignment of all vehicle" << endl;
    cout << "(3)  : View Seat Assignment of a vehicle" << endl;
    cout << "(4)  : Make a Reveration  By Choosing a Car" << endl;
    cout << "(5)  : Make a Reveration  By Choosing a Seat" << endl;
    cout << "(6)  : Remove a Reservation" << endl;
    cout << "(7)  : Change a Reservation" << endl;
    cout << "(8)  : Print Rooster of Players" << endl;
    cout << "(9)  : Print Reservation in a car" << endl;
    cout << "(10) : Print Rooster of Reservation " << endl;
    cout << "(-1) : Quit and Print all Roosters" << endl;
    cout << "[Select by input index of choice]" << endl;
    cin >> choose;

    return choose;
}

int main()
{
    list<Vehicle*> cars;
    list<Player> dodgers;
    list<Seat*> location;
    list<Seat*> temp;
    int choose = -1;
    Player* user;
    Vehicle* assign;

    readInPlayer(cars,dodgers,location);
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
                seatRooster(location);
                break;
            case 3:
                vehicleRooster(cars);
                temp = select(cars)->getSeat();
                seatRooster(temp);
                break;
            case 4:
                playerRooster(dodgers);
                user = able2Res(dodgers);
                if (user != NULL)
                { 
                    system("cls");
                    vehicleRooster(cars);
                    temp = select(cars)->getSeat();
                    reservedSeatViaSeats(temp, user);
                }
                break;
            case 5:
                playerRooster(dodgers);
                user = able2Res(dodgers);
                if (user != NULL)
                {   
                    reservedSeatViaSeats(location, user);
                }
                break;
            case 6:
                playerRooster(dodgers);
                user = able2Rmv(dodgers); 
                if (user != NULL)
                {
                    removeReserved(user);
                    cout << "Reservation is removed" << endl;
                }
                break;
            case 7:
                playerRooster(dodgers);
                user = able2Rmv(dodgers);
                if (user != NULL)
                {   
                    system("cls");
                    removeReserved(user);
                    if (changeHow())
                    {
                        vehicleRooster(cars);
                        temp = select(cars)->getSeat();
                        reservedSeatViaSeats(temp, user);
                    }
                    else
                    {
                        reservedSeatViaSeats(location, user);
                    }
                    if (user->getLocation() == NULL)
                        cout << "Reservation removed unsucessfully changed" << endl;
                };
                break;
            case 8:
                printRooster(dodgers);
                break;
            case 9:
                vehicleRooster(cars);
                assign = select(cars);
                printRooster(assign);
                break;
            case 10:
                printRooster(cars);
                break;
            default:
                break;
        }
        
    } while (choose != -1);

    printRooster(cars);
    printRooster(dodgers);
    for(auto it : cars)
        printRooster(it);
   
    return 0;
}

