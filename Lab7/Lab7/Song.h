//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title  : Lab_1_Library_Header
// Course : Computational problem soving II
// Developer: Nathaniel Valla
// Date :9/3/2022 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Song_Header
#define Song_Header

#include <iostream>
#include <string>

using namespace std;

class Song
{
	private:
		string song_name;
		string song_Artist;
		string song_URL;

	public:

		Song() 
		{
			song_name = "";
		    song_Artist ="";
		    song_URL = "";
		}
		
		Song(string name,string Artist, string URL)
		{
			song_name = name;
			song_Artist = Artist;
			song_URL = URL;
		}

		void DisplaySongInfo()
		{	
			cout << song_name << " by " << song_Artist << endl;
		}


		void PlaySong()
		{   string command;

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

};





#endif