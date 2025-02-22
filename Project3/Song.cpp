//Berkay Simsek 22303338
using namespace std;

#include "Song.h"

Song::Song() {
    name = "";
    artist = "";
    ID = 0;
}

Song::Song(const Song& aSong) {
    name = aSong.name;
    artist = aSong.artist;
    ID = aSong.ID;
}

Song::Song(const string songName, const string artistName, const int songID) {
    name = songName;
    artist = artistName;
    ID = songID;
}

string Song::getSongName() const {
    return name;
}

string Song::getArtistName() const {
    return artist;
}

int Song::getID() const {
    return ID;
}

