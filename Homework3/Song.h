//Berkay Simsek 22303338
#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
private:
    string name;
    string artist;
    int ID;
public:
    Song();
    Song(const Song& aSong);
    Song(const string songName, const string artistName, const int songID);
    string getSongName() const;
    string getArtistName() const;
    int getID() const;
};

#endif //SONG_H
