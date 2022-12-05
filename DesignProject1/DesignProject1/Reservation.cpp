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

using namespace std;

bool changeHow()
{
    set<int> types;
    int input = 1;

    types.insert(1);
    types.insert(2);

    do
    {
        cout << "Choose what you want to do" << endl;
        cout << "(1)  : Make a Reveration  By Choosing a Car" << endl;
        cout << "(2)  : Make a Reveration  By Choosing a Seat" << endl;

        cin >> input;
    } while (types.find(input) == types.end());

    if (input == 1)
        return false;
    else
        return true;
}

void removeReserved(Player* dodger)
{
    Seat* remove;
    remove = dodger->getLocation();
    dodger->addPoints(remove->getPoints());
    remove->removePlayer();
    dodger->removeSeat();

    cout << "Reservation is removed" << endl;
    cout << "Dodger points : " << dodger->getPoints() << endl;
}

void reservedSeatViaSeats(list<Seat>& locations, Player* dodger)
{
    set<int> types;
    bool loop = false;
    int input;
    int cnt = 0;

    for (auto it : locations) types.insert(it.getPoints());

    do
    {
        system("cls");
        cout << setw(4) << right << "|";
        cout << setw(15) << left << "Type of Seats" << "|";
        cout << setw(5) << left << "Points" << endl;
        cout << setfill('-') << setw(49) << right << ' ' << endl;
        cout << setfill(' ');

        for (auto it : types)
        {
            cout << setw(4) << right << "|";
            switch (it)
            {
            case -1:
                cout << setw(15) << left << "Driver" << "|";
                break;
            case  1:
                cout << setw(15) << left << "Center Back" << "|";
                break;
            case  2:
                cout << setw(15) << left << "Side Back" << "|";
                break;
            case  3:
                cout << setw(15) << left << "Compact Back" << "|";
                break;
            case  5:
                cout << setw(15) << left << "Passenger" << "|";
                break;
            }
            if (it == -1)
                cout << setw(5) << right << "N/A" << endl;
            else
                cout << setw(5) << right << it << endl;
        }
        cout << "Dodger points : " << dodger->getPoints() << endl;

        cout << "Dodger points : " << dodger->getPoints() << endl;
        cout << "[Select by selecting point value]" << endl;
        cin >> input;
        if (types.find(input) == types.end())
        {
            cout << "Not a reseverable seat" << endl;
            loop = true;
            system("pause");
        }
        else
            if (input == -1)
            {
                cout << "Not a reseverable seat" << endl;
                loop = true;
                system("pause");
            }
            else
            {
                loop = false;
            }
    } while (loop);

    if (dodger->getPoints() >= input)
    {
        cout << "You have enough points" << endl;
        for (auto it : locations)
        {
            if (it.getPoints() == input)
            {
                if (!it.getReserved())
                {
                    loop = true;
                    break;
                }
                else
                {
                    cnt++;
                    loop = false;
                }
            }
            else
            {
                cnt++;
                loop = false;
            }
        }

        if (loop)
        {
            auto it = locations.begin();
            advance(it, cnt);
            it->setPlayer(*dodger);
            dodger->setLocation(it->getPointer());
            dodger->takePoints(input);

            cout << "Reservation has been made " << endl;
        }
        else
            cout << "No seat of that type available" << endl;
    }
    else
    {
        cout << "You don't have enough points, can't reserve a seat" << endl;
    }
}

void reservedSeatViaCar(Vehicle* car, Player* dodger)
{
    vector<Seat*> postions = car->getSeat();
    set<int> types;
    bool loop = false;
    int input;
    int cnt = 0;
    for (auto it : postions) types.insert(it->getPoints());

    do
    {
        system("cls");
        cout << "The " << car->getVehicleName() << " seats:" << endl;
        cout << setw(4) << right << "|";
        cout << setw(15) << left << "Type of Seats" << "|";
        cout << setw(5) << left << "Points" << endl;
        cout << setfill('-') << setw(49) << right << ' ' << endl;
        cout << setfill(' ');

        for (auto it : types)
        {
            cout << setw(4) << right << "|";
            switch (it)
            {
            case -1:
                cout << setw(15) << left << "Driver" << "|";
                break;
            case  1:
                cout << setw(15) << left << "Center Back" << "|";
                break;
            case  2:
                cout << setw(15) << left << "Side Back" << "|";
                break;
            case  3:
                cout << setw(15) << left << "Compact Back" << "|";
                break;
            case  5:
                cout << setw(15) << left << "Passenger" << "|";
                break;
            }
            if (it == -1)
                cout << setw(5) << right << "N/A" << endl;
            else
                cout << setw(5) << right << it << endl;
        }
        cout << "Dodger points : " << dodger->getPoints() << endl;
        cout << "[Select by selecting point value]" << endl;
        cin >> input;
        if (types.find(input) == types.end())
        {
            cout << "Not a reseverable seat" << endl;
            loop = true;
            system("pause");
        }
        else
            if (input == -1)
            {
                cout << "Not a reseverable seat" << endl;
                loop = true;
                system("pause");
            }
            else
            {
                loop = false;
            }
    } while (loop);

    if (dodger->getPoints() >= input)
    {
        cout << "You have enough points" << endl;
        for (auto it : postions)
        {
            if (it->getPoints() == input)
            {
                if (!it->getReserved())
                {
                    loop = true;
                    break;
                }
                else
                {
                    cnt++;
                    loop = false;
                }
            }
            else
            {
                cnt++;
                loop = false;
            }
        }

        if (loop)
        {
            car->setPassenger(*dodger, cnt);
            dodger->takePoints(input);
            cout << "Reservation has been made " << endl;
        }
        else
            cout << "No seat of that type available" << endl;
    }
    else
    {
        cout << "You don't have enough points, can't reserve a seat" << endl;
    }
}