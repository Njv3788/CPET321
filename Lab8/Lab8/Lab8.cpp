
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include "Song.h"


using namespace std;

int main()
{ 
    list<Song> masterPlayList;
    unordered_map<string,list<Song>> playlists;
    string playlistName = "Master Playlist";
    string nameOfMaster = playlistName;
    int choose;
    bool again = 1;

    cout << "Welcome to the playlist generator" << endl;
    system("pause");
    system("cls");
    
    masterPlayList = Create("my_playlist.txt");
    if(masterPlayList.empty())
        return 0;
    
    playlists.emplace(playlistName,masterPlayList);

    do
    {
        cout << "Select which you would like to do:" << endl;
        cout << "( 1 )  Create  : Play a entire playlist " << endl;
        cout << "( 2 )  Display : play a song from a playList  " << endl;
        cout << "( 3 )  Delete  : Play a entire playlist " << endl;
        cout << "( 4 )  Play1   : play a song from a playList  " << endl;
        cout << "( 5 )  Play2   : Play a entire playlist " << endl;
        cout << "( -1 ) Quit    : Quits and generates .txt of playlists" << endl;

        cin >> choose;
        system("cls");

        switch(choose)
        {
            case -1:
                again = 0;
                printPlaylist(playlists, nameOfMaster);
                break;
            case 1:
                if(playlists.size() < 4)
                { 
                    cout << "Please enter name of new playlist: " << endl;
                    cin.ignore();
                    getline(cin, playlistName);
                    playlists.emplace(playlistName, Create(playlists.at(nameOfMaster)));
                    cout << "Playlist is generated: " << endl;
                    DisplayPlaylistInfo(playlists.at(playlistName));
                }
                else
                {
                    cout << "You have the max number of playlists.\n";
                    cout << "Please delete one before adding a new one." << endl;
                }
                break;
            case 2:
                playlistName = DisplayPlaylists(playlists);
                if (playlistName == "")
                    cout << "Not a Playlists" << endl;
                else
                    DisplayPlaylistInfo(playlists.at(playlistName));
                break;
            case 3:
                playlistName = DisplayPlaylists(playlists);

                if(playlistName == nameOfMaster)
                    cout << "Master Playlist unable to erase" << endl;
                else if (playlistName == "")
                    cout << "Not a Playlists" << endl;
                else  
                    playlists.erase(playlistName);
                break;
            case 4:
                playlistName = DisplayPlaylists(playlists);
                if (playlistName == "")
                    cout << "Not a Playlists" << endl;
                else
                    Play1(playlistName,playlists.at(playlistName));
                break;
            case 5:
                playlistName = DisplayPlaylists(playlists);
                if (playlistName == "")
                    cout << "Not a Playlists" << endl;
                else
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