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


void readInPlayer(list<Vehicle*>& cars, list<Player>& dodgers, list<Seat*>& locations)
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
            cars.push_back(new Vehicle(temp, locations));
            dodgers.push_back(Player(name, -1));
            cars.back()->setPassenger(dodgers.back(), 0);
        }
        else
        {
            dodgers.push_back(Player(name, stoi(temp)));
        }


    } while (!(inFile.eof()));

    return;
};

void seatRooster(list<Seat*>& location)
{
    int points;
    int cnt = 1;

    cout << setw(4) << right << "|";
    cout << setw(15) << left << "Vehicle" << "|";
    cout << setw(15) << "Type of seat" << "|";
    cout << setw(15) << "Resevation Status" << "|";
    cout << setw(15) << "Dodger " << endl;
    cout << setfill('-') << setw(70) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : location)
    {
       
        cout << setw(3) << right << cnt++ << "|";
        cout << setw(15) << left << it->getVehicle()->getVehicleName() << "|";
        points = it->getPoints();

        switch (points)
        {
        case -1:
            cout << setw(15) << "Driver" << "|";
            break;
        case  1:
            cout << setw(15) << "Center Back" << "|";
            break;
        case  2:
            cout << setw(15) << "Side Back" << "|";
            break;
        case  3:
            cout << setw(15) << "Compact Back" << "|";
            break;
        case  5:
            cout << setw(15) << "Passenger" << "|";
            break;
        }

        if (it->getReserved())
        {
            cout << right << setw(17) << "Resereved" << "|";
            cout << setw(15) << it->getPlayer()->getName() << endl;
        }
        else
        {
            cout << right << setw(17) << "Open" << "|";
            cout << setw(15) << "None" << endl;
        }

    }

};

void vehicleRooster(list<Vehicle*>& cars)
{
    bool status;
    int cnt = 1;

    cout << setw(4) << right << "|";
    cout << setw(15) << left << "Vehicle" << "|";
    cout << setw(15) << left << "Driver" << "|";
    cout << setw(17) << "Resevation Status" << endl;
    cout << setfill('-') << setw(50) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : cars)
    {
        status = true;
        cout << setw(3) << right << cnt++ << "|";
        cout << setw(15) << left << it->getVehicleName() << "|";

        cout << setw(15) << it->getSeat().front()->getPlayer()->getName() << "|";

        for (auto loop : it->getSeat())
        {
            if (!loop->getReserved())
            {
                status = false;
                break;
            }
        }

        if (status)
            cout << right << setw(17) << "Full" << endl;
        else
            cout << right << setw(17) << "Seats Available" << endl;
    }
}

void playerRooster(list<Player>& dodgers)
{
    int cnt = 1;
    int points;

    cout << setw(4) << right << "|";
    cout << setw(20) << left << "Dodger" << "|";
    cout << setw(7) << "Points" << "|";
    cout << setw(15) << "Seat Assigned" << "|";
    cout << setw(18) << "Vehicle Assigned" << endl;
    cout << setfill('-') << setw(67) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : dodgers)
    {
        cout << setw(3) << right << cnt++ << "|";
        cout << setw(20) << left << it.getName() << "|";
        if (-1 == it.getPoints())
            cout << setw(7) << right << "n/a" << "|";
        else
            cout << setw(7) << right << it.getPoints() << "|";

        if (it.getLocation() == NULL)
        {
            cout << setw(15) << "None" << "|";
            cout << setw(17) << "None" << endl;
        }
          
        else
        {
            points = it.getLocation()->getPoints();
            switch (points)
            {
                case -1:
                    cout << setw(15) << "Driver" << "|";
                    break;
                case  1:
                    cout << setw(15) << "Center Back" << "|";
                    break;
                case  2:
                    cout << setw(15) << "Side Back" << "|";
                    break;
                case  3:
                    cout << setw(15) << "Compact Back" << "|";
                    break;
                case  5:
                    cout << setw(15) << "Passenger" << "|";
                    break;
            }
            cout << setw(17) << it.getLocation()->getVehicle()->getVehicleName() << endl;
        }
    }
}

void printRooster(list<Player>& dodgers)
{
    ofstream outFile;
    int cnt = 1;

    outFile.open("Player_Rooster.txt");

    outFile << setw(4) << right << "|";
    outFile << setw(20) << left << "Dodger" << "|"; 
    outFile << setw(7) << "Points" << "|";
    outFile << setw(15) << "Seat Assigned" << "|";
    outFile << setw(18) << "Vehicle Assigned" << endl;
    outFile << setfill('-') << setw(67) << right << ' ' << endl;
    outFile << setfill(' ');

    for (auto it : dodgers)
    {
        outFile << setw(3) << right << cnt++ << "|";
        outFile << setw(20) << left << it.getName() << "|";
        if (-1 == it.getPoints())
            outFile << setw(7) << right << "n/a" << "|";
        else
            outFile << setw(7) << right << it.getPoints() << "|";


        if (it.getLocation() == NULL)
        {
            outFile << setw(15) << "None" << "|";
            outFile << setw(17) << "None" << endl;
        }
        else
        {
            switch (it.getLocation()->getPoints())
            {
            case -1:
                outFile << setw(15) << "Driver" << "|";
                break;
            case  1:
                outFile << setw(15) << "Center Back" << "|";
                break;
            case  2:
                outFile << setw(15) << "Side Back" << "|";
                break;
            case  3:
                outFile << setw(15) << "Compact Back" << "|";
                break;
            case  5:
                outFile << setw(15) << "Passenger" << "|";
                break;
            }
            outFile << setw(17) << it.getLocation()->getVehicle()->getVehicleName() << endl;
        }
    }

    outFile.close();
}

void printRooster(list<Vehicle*>& cars)
{
    ofstream outFile;
    int cnt = 1;

    outFile.open("Vehicle_Rooster.txt");

    outFile << setw(4) << right << "|";
    outFile << setw(15) << left << "Vehicle" << "|";
    outFile << setw(15) << "Type of seat" << "|";
    outFile << setw(15) << "Resevation Status" << "|";
    outFile << setw(15) << "Dodger " << endl;
    outFile << setfill('-') << setw(70) << right << ' ' << endl;
    outFile << setfill(' ');

    for (auto it : cars)
    {
        for (auto loop : it->getSeat())
        {
            outFile << setw(3) << right << cnt++ << "|";
            outFile << setw(15) << left << it->getVehicleName() << "|";

            switch (loop->getPoints())
            {
            case -1:
                outFile << setw(15) << "Driver" << "|";
                break;
            case  1:
                outFile << setw(15) << "Center Back" << "|";
                break;
            case  2:
                outFile << setw(15) << "Side Back" << "|";
                break;
            case  3:
                outFile << setw(15) << "Compact Back" << "|";
                break;
            case  5:
                outFile << setw(15) << "Passenger" << "|";
                break;
            }
            
            if (loop->getReserved())
            {
                outFile << right << setw(17) << "Resereved" << "|";
                outFile << setw(15) << loop->getPlayer()->getName() << endl;
            }
            else
            {
                outFile << right << setw(17) << "Open" << "|";
                outFile << setw(15) << "None" << endl;
            }

        }
    }
    outFile.close();
}

void printRooster(Vehicle * car)
{
    ofstream outFile;
    string temp;
    string key = " ";
    int points;
    bool reserved;
    int cnt = 1;

    temp = car->getVehicleName();
    do
        // loop until all space are out of playlist name
    {
        points = temp.rfind(key);
        if (points != string::npos)
            // if space is found in temp replace with underscore
            // set space to true
        {
            temp = temp.replace(points, key.length(), "_");
            reserved = true;
        }
        else
            // else sets space to flase
        {
            reserved = false;
        }

    } while (reserved);

    outFile.open((temp + ".txt").c_str());

    outFile << setw(4) << right << "|";
    outFile << setw(15) << left << "Vehicle" << "|";
    outFile << setw(15) << "Type of seat" << "|";
    outFile << setw(15) << "Resevation Status" << "|";
    outFile << setw(15) << "Dodger " << endl;
    outFile << setfill('-') << setw(70) << right << ' ' << endl;
    outFile << setfill(' ');

    for (auto loop : car->getSeat())
    {
        outFile << setw(3) << right << cnt++ << "|";
        outFile << setw(15) << left << car->getVehicleName() << "|";

        switch (loop->getPoints())
        {
        case -1:
            outFile << setw(15) << "Driver" << "|";
            break;
        case  1:
            outFile << setw(15) << "Center Back" << "|";
            break;
        case  2:
            outFile << setw(15) << "Side Back" << "|";
            break;
        case  3:
            outFile << setw(15) << "Compact Back" << "|";
            break;
        case  5:
            outFile << setw(15) << "Passenger" << "|";
            break;
        }

        if (loop->getReserved())
        {
            outFile << right << setw(17) << "Resereved" << "|";
            outFile << setw(15) << loop->getPlayer()->getName() << endl;
        }
        else
        {
            outFile << right << setw(17) << "Open" << "|";
            outFile << setw(15) << "None" << endl;
        }
    }

    outFile.close();
}
