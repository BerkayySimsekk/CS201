//Berkay Simsek 22303338
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "User.h"
#include "Song.h"

class User;

class Playlist {
private:
    int ID;
    User* user;
    LinkedList<Song> songs;
public:
    Playlist();
    ~Playlist();
    Playlist(Playlist& aPlaylist);
    Playlist(const int playlistID, User* assignedUser);
    int getID() const;
    User* getAssignedUser();
    LinkedList<Song>& getSongs();
};

#endif //PLAYLIST_H
