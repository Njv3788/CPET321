//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Playlist_Header
#define Playlist_Header

#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"
#include <map>
#include <list>
#include <set>
using namespace std;

Song::Song()
// constucts a song with data set to ""
{
    song_name = "";
    song_Artist = "";
    song_URL = "";
}


Song::Song(string name, string Artist, string URL)
// constucts a song  and aside data members
// song_name gets name, 
// song_Artist gets Artist,
// song_URL gets  URL;
{
    song_name = name;
    song_Artist = Artist;
    song_URL = URL;
}

void Song::DisplaySongInfo()
// Displays the Song in format of 
// Name by Artist
{
    cout << song_name << " by " << song_Artist << endl;
}

void Song::PlaySong()
// Displays Playing : Song info
// Create a command to open the URL 
// Run command and wait till user closed it and press any key
{
    string command;

    // Display:: Playing : Song info
    cout << "Playing : ";
    DisplaySongInfo();

    //Create Command Line & Call it
    command = "start chrome --window-size=250,675 " + song_URL;
    const char* system_command = command.c_str();
    system(system_command);

    //Close the Brower Window to Continue
    cout << "\nClose the Browser Window to Continue, then ..." << endl;
    system("pause");
}

void printPlaylist(map<string, list<Song>>& playlists, string& master)
// Given Map of Playlists and iterators throught it
// For each playlist besides master converts spaces to underscores
// Generates txt file for playlist 
// Prints song info to file
{
    bool space = true;
    string temp;
    string key = " ";
    size_t found;
    ofstream outFile;

    for (auto i : playlists)
    {
        if (master != i.first)
        // if not master 
        {
            
            temp = i.first; //puts name in storage loaction to change it
           
            do
            // loop until all space are out of playlist name
            {
                found = temp.rfind(key);
                if (found != string::npos)
                // if space is found in temp replace with underscore
                // set space to true
                {
                    temp = temp.replace(found, key.length(), "_");
                    space = true;
                }
                else
                // else sets space to flase
                {
                    space = false;
                }

            } 
            while (space);

            outFile.open((temp + ".txt").c_str()); //open file
            for (auto j : i.second)
            {
                outFile << j.song_name << endl;    //output song name to file 
                outFile << j.song_Artist << endl;  //output song artist to file 
                outFile << j.song_URL << endl;     //output song url to file 
            }
            outFile.close();                       //close file

            cout << temp + ".txt" <<" created." << endl;

        }
    }
    cout << "Thank you please again" << endl;
}

void DisplayPlaylistInfo(list<Song>& playlist)
//iterates through a given playlist 
//provides postion in playlist then song info
// ie ( i ) Song by Artists
{   
    int postion = 1;
    for (auto i : playlist)
    {
        cout << "( " << postion++ << " ) ";
        i.DisplaySongInfo();
    }
}

string DisplayPlaylists(map<string, list<Song>>& playlists)
//iterates through map op of Playlist gives postion, name and Size
//Has user selsct playlist 
//Advances to postion and finds name of wanted playlist 
{
    int postion = 1;
    set<int> track;
    string veiw;
    
    cout << "Your playlists include :" << endl;

    for (auto i : playlists)
    //iterates through map op of Playlist gives postion, name and size
    {
        cout << "( " << postion++ << " ) " << i.first << " has ";
        cout << i.second.size() << " songs in it" << endl;
    }

    for (int i = 1; i <= playlists.size(); i++) { track.insert(i); }
    //generates set of postions in map of playlists

    cin >> postion;

    if (!(track.find(postion) == track.end()))
    //checks to see if postion is in set of postion
    //if so find name of playlists
    {
        auto it = playlists.begin();
        for (int i = 1; i < postion; i++) {it++;}
        veiw = it->first;
    }
    else
    //else assign empty String
    {
        veiw = "";
    }
    
    //return name of playists
    return veiw;
}

list<Song> Create(string file)
//is given file name of master playlist
//reads through file and genenator list of Songs
//if file open fails return empty list
{
    ifstream inFile;

    string song_name;
    string song_Artist;
    string song_URL;
    list<Song> playlist;

    inFile.open(file.c_str());
    //open file

    if (!inFile.is_open())
    // if not open return to main with empty playlist
    {
        cout << "File unable to be found or is bad" << endl;
        return playlist;
    }

    do
    //loop till end of file
    {
        getline(inFile, song_name);    // gets name of Song
        getline(inFile, song_Artist);  // gets artist of song
        getline(inFile, song_URL);     // gets URL of song
        playlist.push_back(Song(song_name, song_Artist, song_URL));
        //constuct new song and put it into play lists
    } 
    while (!(inFile.eof()));
    system("cls");

    return playlist;
}

list<Song> Create(list<Song>& master)
// Given Master Playlist
// Has user pick up to five song add to playlists
// Returns new playlists
{ 
    int max = 5;
    int postion;
    set<int> track;
    list<Song> newPlaylist;

    for (int i = 1; i <= master.size(); i++) { track.insert(i);}
    //generates set of postions in master playlists

    for (int i = 1; i <= max; i)
    //loop only max number of times clear 
    //clear after each loops
    {
        cout << "Select which song you would like to add" << endl;
        DisplayPlaylistInfo(master);
        cout << "( -1 ) No more: " << endl;

        cin >> postion;
        system("cls");

        if (!(track.find(postion) == track.end()))
        //checks to see if postion is in set of playlist postions
        //if so add song to playlist and increment by one       
        {
            auto it = master.begin();
            for (int i = 1; i < postion; i++){it++;}
           
            cout << "Adding : ";
            it->DisplaySongInfo();
            newPlaylist.push_back(*it);
            i++;
        }
        else
        //else print not a playlists unless -1
        {
            if (postion == -1)
            // if -1 break
            {
                break;
            }    
            cout << "Not a track in the master playlist" << endl;

        }
        system("pause");
        system("cls");
    }
    return newPlaylist;
}

void Play1(string& name,list<Song>& playlist)
//given name of playlist along with playlist 
//Displays playlist information
//Ask user for postion of desired song
//Finds song and plays it 
{
    set<int> track;
    int postion;

    for (int i = 1; i <= playlist.size(); i++){track.insert(i);}
    //generates set of postions in playlists

    cout << name << " playlist has been selected. " << endl;
    DisplayPlaylistInfo(playlist);

    cin >> postion;

    if (!(track.find(postion) == track.end()))
    //checks to see if postion is in set of playlist postions
    //if so add song to playlist and increment by one       
    {
        auto it = playlist.begin();
        for (int i = 1; i < postion; i++) { it++; }
        it->PlaySong();
    }
    else
    //else display not a track
    {
        cout << "Not a track in the playlist" << endl;
    }

}

void Play2(string& name, list<Song>& playlist)
//given name of playlist along with playlist 
//Displays playlist information Pauses
//iterates through playlist and play each song
{   
    cout << name << " playlist has been selected. " << endl;
    DisplayPlaylistInfo(playlist);
    system("pause");
    
    cout <<"Playing all of " << name << endl;
    for(Song i : playlist) {i.PlaySong();}
    
    cout << name << " playlist has end. " << endl;
    system("pause");
    system("cls");
}

#endif