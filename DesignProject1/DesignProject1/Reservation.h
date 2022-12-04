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
#include <set>
#include "seat.h"
#include "vehicle.h" 
#include "player.h"


using namespace std;
template <typename T>
    T* select(list<T>& container)
    {  
        int input;
        T* lookHere = NULL;
        do
        {   
            cout << "[Input number by name to select]" << endl;
            cin >> input;
            if (input <= container.size())
            {
                auto it = container.begin();
                advance(it, input - 1);
                lookHere = it->getPointer();
            }
            else
            {
                cout << "Not a memebr of the list" << endl;
            }
                
        } while (lookHere == NULL);

        return lookHere;
    }
Player* able2Res(list<Player>& dodgers)
{
    int input;
    Player* lookHere;

    cout << "Who is changing their Resevation status?" << endl;
    cout << "[Input number by mname to select]" << endl;
    
    lookHere = select(dodgers);
    input = lookHere->getPoints();

    cout << input << endl; 
    system("cls");
    if (lookHere->getLocation() != NULL)
    {
        cout << "Dodger is already has a reservation." << endl;
        lookHere = NULL;
    }
    else
        if (input == 0) 
        { 
            cout << "Dodger has no points, unable to change Resevation status." << endl;
            lookHere = NULL;
        }
           
    return lookHere;
}

Player* able2Rmv(list<Player>& dodgers)
{
    Player* hereLook = NULL;
    Seat* lookHere;

    cout << "Who is changing their Resevation status?" << endl;
    cout << "[Input number by mname to select]" << endl;
    
    hereLook = select(dodgers);
    lookHere = hereLook->getLocation();

    if (lookHere == NULL)
    {
        cout << "Dodger isn't in a car" << endl; 
        hereLook = NULL;
    }    
    else
        if (lookHere->getPoints() == -1)
        {
            cout << "Dodger is a Driver" << endl;
            hereLook = NULL;
        }
    return hereLook;
}

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
    int cnt = 1;

    cout << setw(4) << right << "|";
    cout << setw(15) << left << "Vehicle" << "|";
    cout << setw(15) << "Type of seat" << "|";
    cout << setw(6)  << "Points" << "|";
    cout << setw(15) << "Resevation Status" << "|";
    cout << setw(15) << "Dodger " << endl;
    cout << setfill('-') << setw(77) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : cars)
    {
        postions = it.getSeat();
        
        for(auto loop : postions)
        { 
            cout << setw(3) << right << cnt++ << "|";
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
            {
                cout << right << setw(17) << "Resereved" << "|";
                cout << setw(15) << loop.getPlayer()->getName()<< endl;
            }
            else
            {
                cout << right << setw(17) << "Open" << "|";
                cout << setw(15) << "None" << endl;
            }
                
            
        }
    }

};

void vehicleRooster(list<Vehicle> cars)
{
    bool status;
    vector<Seat> postions;
    int cnt = 1;

    cout << setw(4)  << right << "|";
    cout << setw(15) << left << "Vehicle" << "|";
    cout << setw(15) << left << "Driver" << "|";
    cout << setw(17) << "Resevation Status" << endl;
    cout << setfill('-') << setw(50) << right << ' ' << endl;
    cout << setfill(' ');

    for (auto it : cars)
    {
        status = true;
        cout << setw(3)  << right << cnt++ << "|";
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
    int cnt = 1;
    int points;
    cout << setw(4) << right << "|";
    cout << setw(20) << left << "Dodger" << "|";
    cout << setw(7) << "Points" << "|";
    cout << setw(15) << "Assignment" << endl;
    cout << setfill('-') << setw(49) << right << ' ' << endl;
    cout << setfill(' ');
    
    for (auto it : dodgers)
    {
        cout << setw(3) << right << cnt++ << "|";
        cout << setw(20) << left << it.getName() <<  "|";
        if (-1 == it.getPoints())
            cout << setw(7) << right << "n/a" << "|";
        else
            cout << setw(7) << right << it.getPoints() << "|" ;
        
        if (it.getLocation() == NULL)
            points = 0;
        else
            points = it.getLocation()->getPoints();
        
        switch (points)
        {
            case -1:
                cout << setw(15) << "Driver" << endl;
                break;
            case 0:
                cout << setw(15) << "None" << endl;
                break;
            case  1:
                cout << setw(15) << "Center Back" << endl;
                break;
            case  2:
                cout << setw(15) << "Side Back" << endl;
                break;
            case  3:
                cout << setw(15) << "Compact Back" << endl;
                break;
            case  5:
                cout << setw(15) << "Passenger" << endl;
                break;
        }
    }
   
}

vector<Seat*> generatorListOfSeats(list<Vehicle>& cars)
{
    vector<Seat*> location;

    for (auto it : cars)
    {
        for (int j = 0; j < it.postions.size(); j++)
        {
            cout << it.getSeat(j)->getPointer() << endl;
            location.push_back(it.getSeat(j)->getPointer());
        }
    }
    cout << endl;
    return location;
};

void reservedSeatViaCar(Vehicle *car, Player *dodger)
{
    vector<Seat> postions = car->getSeat();
    set<int> types;
    bool loop = false;
    int input;
    int cnt = 0;
    for (auto it : postions) types.insert(it.getPoints());
    
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
                    cout << setw(15) << left << "Passenger" << "|" ;
                    break;
            }
            if(it == -1)
                cout << setw(5) << right << "N/A" << endl;
            else
                cout << setw(5) << right << it << endl;
        }  
        cout <<"Dodger points : " << dodger->getPoints() << endl;
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

#endif

