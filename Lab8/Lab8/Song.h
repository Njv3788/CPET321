//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Song_Header
#define Song_Header

#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"
#include "Playlist.h"
#include <map>
#include <list>
#include <set>

using namespace std;

class Song
{
	private:
		string song_name;
		string song_Artist;
		string song_URL;

	public:

		//constuctor
		Song();
		Song(string name, string Artist, string URL);

		//acessors 
		void DisplaySongInfo();
		void PlaySong();

		//friend function
		friend void printPlaylist(map<string, list<Song>>&, string&);

};

void DisplayPlaylistInfo(list<Song>& playlist);
list<Song> Create(string);
void Play1(string&, list<Song>&);
void Play2(string&, list<Song>&);
string DisplayPlaylists(map<string, list<Song>>&);
list<Song> Create(list<Song>&);


#endif