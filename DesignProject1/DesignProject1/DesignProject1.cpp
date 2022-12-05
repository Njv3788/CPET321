// DesignProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Reservation.h"
#include "vehicle.h" 
#include "player.h"
#include "Rooster.h"

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
    cout << "(6)  : Change a Reservation" << endl;
    cout << "(7)  : Print Rooster of Players" << endl;
    cout << "(8)  : Print Reservation in a car" << endl;
    cout << "(9)  : Print Rooster of Reservation " << endl;
    cout << "(-1) : Quit" << endl;
    cin >> choose;

    return choose;
}

int main()
{
    
    list<Vehicle> cars;
    list<Player> dodgers;
    list<Seat> location;
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
                seatRooster(cars);
                break;
            case 3:
                playerRooster(dodgers);
                user = able2Res(dodgers);
                if (user != NULL)
                { 
                    system("cls");
                    vehicleRooster(cars);
                    assign = select(cars);
                    reservedSeatViaCar(assign, user);
                }
                break;
            case 4:
                playerRooster(dodgers);
                user= able2Res(dodgers);
                if (user != NULL)
                {   
                    system("cls");
                    reservedSeatViaSeats(location, user);
                }
                break;
            case 5:
                playerRooster(dodgers);
                user = able2Rmv(dodgers); 
                if (user != NULL)
                {
                    removeReserved(user);
                }
                break;
            case 6:
                playerRooster(dodgers);
                user = able2Rmv(dodgers);
                if (user != NULL)
                {   
                    system("cls");
                    removeReserved(user);
                    if (changeHow())
                    {
                        system("cls");
                        vehicleRooster(cars);
                        assign = select(cars);
                        reservedSeatViaCar(assign, user);
                    }
                    else
                    {
                        system("cls");
                        reservedSeatViaSeats(location, user);
                    }
                };
                break;
            case 7:
                printRooster(dodgers);
                break;
            case 8:
                vehicleRooster(cars);
                assign = select(cars);
                printRooster(*assign);
                break;
            case 9:
                printRooster(cars);
                break;
            default:
                break;
        }
        
    } while (choose != -1);
   
    return 0;
}

