//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Playlist_Header
#define Playlist_Header

#include <iostream>
#include <string>
#include <List>
#include "Song.h"

void DisplayPlaylistInfo (list<Song>& playlist);
list<Song> Create(string);
void Play1(string&, list<Song>&);
void Play2(string&, list<Song>&);
string DisplayPlaylists(unordered_map<string, list<Song>>&);
list<Song> Create(list<Song>&);


#endif