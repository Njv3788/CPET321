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
#include "Playlist.h"
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

void DisplayPlaylistInfo(list<Song>& playlist)
{   
    int postion;
    postion = 1;
    for (auto i = playlist.begin(); i != playlist.end(); i++)
    {
        cout << "( " << postion++ << " ) ";
        i->DisplaySongInfo();
    }
}

string DisplayPlaylists(unordered_map<string, list<Song>>& playlists)
{
    
    int it = 1; 
    int postion;
    set<int> track;
    string veiw;
    
    cout << "Your playlists include :" << endl;

    for (auto i : playlists)
    {
        cout << "( " << it++ << " ) ";
        cout << i.first << " has ";
        cout << i.second.size() << " songs in it" << endl;
    }

    for (int i = 1; i <= playlists.size(); i++)
    {
        track.insert(i);
    }

    cin >> postion;

    if (!(track.find(postion) == track.end()))
    {
        auto it = playlists.begin();
        for (int i = 1; i < postion; i++)
            it++;
        veiw = it->first;
    }
    else
    {
        veiw = "";
    }
    
    return veiw;
}

list<Song> Create(string file)
{
    ifstream inFile;

    string song_name;
    string song_Artist;
    string song_URL;
    list<Song> playlist;
    int postion;

    inFile.open(file);

    if (!inFile.is_open())
    {
        cout << "File unable to be found or is bad" << endl;
        return playlist;
    }

    postion = 1;
    do
    {
        getline(inFile, song_name);
        getline(inFile, song_Artist);
        getline(inFile, song_URL);
        playlist.push_back(Song(song_name, song_Artist, song_URL));
    } while (!(inFile.eof()));

    return playlist;
}

list<Song> Create(list<Song>& master)
{ 
    int max = 5;
    int postion;
    set<int> track;
    list<Song> newPlaylist;

    for (int i = 1; i <= master.size(); i++)
        track.insert(i);

    for (int i = 1; i <= max; i++)
    {
        cout << "Select which song you would like to add" << endl;
        DisplayPlaylistInfo(master);
        cout << "( -1 ) No more: " << endl;

        cin >> postion;

        if (!(track.find(postion) == track.end()))
        {
            auto it = master.begin();
            for (int i = 1; i < postion; i++)
                it++;

            newPlaylist.push_back(*it);
        }
        else
        {
            if (postion == -1)
            {
                system("cls");
                break;
            }
            else
                cout << "Not a track in the playlist" << endl;
        }
        system("cls");

    }
    return newPlaylist;
}

void Play1(string& name,list<Song>& playlist)
{
    set<int> track;
    int postion;

    for (int i = 1; i <= playlist.size(); i++)
        track.insert(i);
    cout << name << endl;
    DisplayPlaylistInfo(playlist);

    cin >> postion;

    if (!(track.find(postion) == track.end()))
    {
        auto it = playlist.begin();
        for (int i = 1; i < postion; i++)
            it++;
        it->PlaySong();
    }
    else
    {
        cout << "Not a track in the playlist" << endl;
        system("pause");
    }
    system("cls");

}

void Play2(string& name, list<Song>& playlist)
{
    cout << name << " playlist has been selected. " << endl;

    system("pause");
    for(Song i : playlist)
    {
        i.PlaySong();
        system("cls");
    }
    
    cout << name << " playlist has end. " << endl;
    system("pause");
}

void printPlaylist(unordered_map<string, list<Song>>& playlists, string& master)
{
    int it = 1;
    bool space = true;
    string temp;
    string key = " ";
    size_t found;
    ofstream outFile;


    for (auto i : playlists)
    {
        if (master != i.first)
        {
            
            temp = i.first;
            do
            {
                found = temp.rfind(key);
                if (found != string::npos)
                    temp = temp.replace(found, key.length(), "_");
                else
                    space = false;

            } while (space);
            cout << temp << endl;

            outFile.open((temp + ".txt").c_str());
            for (auto j : i.second)
            {
                outFile << j.song_name << endl;
                outFile << j.song_Artist << endl;
                outFile << j.song_URL << endl;
            }
            outFile.close();
            cout << temp + ".txt" <<" created.";

        }
    }
}

#endif