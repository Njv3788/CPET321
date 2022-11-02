
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <set>
#include "Song.h"

using namespace std;

int main()
{
    ifstream inFile;

    string song_name;
    string song_Artist;
    string song_URL;

    
    list<Song> playlist;
    set<int> track;
    int postion;

    inFile.open("my_playlist.txt");
    
    if (!inFile.is_open())
    {
        cout << "File unable to be found or is bad" << endl;
    }
    else
    {   
        postion = 1;
        do
        {
            getline(inFile,song_name);
            getline(inFile,song_Artist);
            getline(inFile,song_URL);
            playlist.push_back(Song(song_name, song_Artist, song_URL));
            track.insert(postion++);
        } 
        while (!(inFile.eof()));

        do 
        { 
            postion = 1;
            for(auto i = playlist.begin(); i != playlist.end(); i++)
            {   
                cout << "( " << postion++ << " ) ";
                i->DisplaySongInfo();
            }
            
            cout << "( " << -1 << " ) Quit ";
            cout << endl;
            cin >> postion;

            if(postion != -1)
            { 
                if(!(track.find(postion) == track.end()))
                { 
                    auto it = playlist.begin();
                    for (int i = 1; i < postion; i++)
                    {
                        it++;
                    }
                    it->PlaySong();
                }
                else
                {
                    cout << "Not a track in the playlist" << endl;
                }
            }
            else
            {
                break;
            }
            system("cls");

        } 
        while (true);

        postion = 0;
        for (auto i = playlist.begin(); i != playlist.end(); i++)
        {
            cout << "( " << ++postion << " ) ";
            i->DisplaySongInfo();
        }
        system("pause");
    }

    return 0;
}