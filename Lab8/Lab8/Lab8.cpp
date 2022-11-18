
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include <map>
#include "Song.h"


using namespace std;

int main()
{ 
    list<Song> masterPlayList;
    map<string,list<Song>> playlists; // map of playlist with name as key
    string playlistName = "Master Playlist";
    string nameOfMaster = playlistName;
    string filename;
    int choose;
    bool again = 1;

    //Welcome message
    cout << "Welcome to the playlist generator" << endl;
    cout << "Please file name of master playlist: " << endl;
    getline(cin, filename); // my_playlist.txt
    system("cls");
    
    masterPlayList = Create(filename); 
    //creates Master Playlist
    
    if (masterPlayList.empty()) { return 0; }
    //if master playlist is empty file failed to open
    
    playlists.emplace(playlistName,masterPlayList);
    //Put master playlist into map of playlists

    do
    {
        //Main Menu
        cout << "Select which you would like to do:" << endl;
        cout << "( 1 )  Create  : Create up three playlist of 5 songs " << endl;
        cout << "( 2 )  Display : Display the playlists and choose which to veiw the contents of" << endl;
        cout << "( 3 )  Delete  : Delete a playlist except for the master playlist   " << endl;
        cout << "( 4 )  Play1   : Choose a playlist and play a single song from it " << endl;
        cout << "( 5 )  Play2   : Choose a playlist and play all of it " << endl;
        cout << "( -1 ) Quit    : Quits and generates .txt of playlists" << endl;

        cin >> choose; // use inputs the taste they want to be preformed
        system("cls");

        switch(choose)
        {
            case -1: 
                again = 0; // set again to be false
                printPlaylist(playlists, nameOfMaster);
                //prints all but master playlist to files 
                break;
            case 1:
                if(playlists.size() < 4)
                //if there are less then four playlist the user is allowed to make more
                { 
                    cout << "Please enter name of new playlist: " << endl;
                    cin.ignore();
                    getline(cin, playlistName);
                    //enter name of playlists

                    if ((playlists.find(playlistName) == playlists.end()))
                    //if name of play not already used a key
                    { 
                        system("cls");
                        playlists.emplace(playlistName, Create(playlists.at(nameOfMaster)));
                        cout << "Playlist is generated: " << endl;
                        DisplayPlaylistInfo(playlists.at(playlistName));
                    }
                    else 
                    //else creation of failed failed
                    {
                        cout << "Playlist creation failed name already used" << endl;
                    }
                }
                else
                //else to create a new playlist delete playlist
                {
                    cout << "You have the max number of playlists.\n";
                    cout << "Please delete one before adding a new one." << endl;
                }
                break;
            case 2:
                playlistName = DisplayPlaylists(playlists); //display and user pick
                system("cls");
                
                if (playlistName == "") //if playlistName empty 
                    cout << "Not a Playlists" << endl;
                else // Display list
                {
                    cout << playlistName << " playlist has been selected. " << endl;
                    DisplayPlaylistInfo(playlists.at(playlistName));
                }
                break;
            case 3:
                playlistName = DisplayPlaylists(playlists); //display and user pick

                if(playlistName == nameOfMaster) // if master do not let user delete playlist
                    cout << "Master Playlist unable to erase" << endl;
                else if (playlistName == "") //if playlistName empty 
                    cout << "Not a Playlists" << endl;
                else  // earse playlist
                    playlists.erase(playlistName);
                break;
            case 4:
                playlistName = DisplayPlaylists(playlists); //display and user pick
                if (playlistName == "")  //if playlistName empty 
                    cout << "Not a Playlists" << endl;  
                else //play1
                    Play1(playlistName,playlists.at(playlistName));
                break;
            case 5:
                playlistName = DisplayPlaylists(playlists); //display and user pick
                if (playlistName == "")  //if playlistName empty 
                    cout << "Not a Playlists" << endl;
                else //play2
                    Play2(playlistName, playlists.at(playlistName));
                break;
            default:
               cout << "Not available please try again " << endl;
               break;
        }
        system("pause");
        system("cls");

    }
    while (again);

    return 0;
}