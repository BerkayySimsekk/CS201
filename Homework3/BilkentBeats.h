//Berkay Simsek 22303338
#ifndef BILKENTBEATS_H
#define BILKENTBEATS_H

#include <string>
using namespace std;

#include "LinkedList.cpp"
#include "User.h"
#include "Song.h"

class BilkentBeats {
private:
    LinkedList<User> users;
    LinkedList<Song> songs;

public:
    BilkentBeats();
    ~BilkentBeats();

    void addUser( const int userId, const string userName );
    void removeUser( const int userId );
    void printUsers() const;

    void addSong( const int songID, const string songName, const string artists );
    void removeSong( const int songID );
    void printSongs() const;

    void addPlaylist( const int userId, const int playlistId );
    void removePlaylist( const int userId, const int playlistId );
    void addSongToPlaylist( const int playlistId, const int songId );
    void removeSongFromPlaylist( const int playlistId, const int songId );
    void printSongsInPlaylist( const int playlistId ) const;

    void sortUsersByAscendingOrder();
    void sortSongsByAscendingOrder();
};

#endif //BILKENTBEATS_H
