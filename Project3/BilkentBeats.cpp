//Berkay Simsek 22303338
#include "BilkentBeats.h"

#include <iostream>
using namespace std;

BilkentBeats::BilkentBeats() {}

BilkentBeats::~BilkentBeats() {}

//a method that sorts the users by creating a temporary user object by using the copy constructor in the User class and swaps the user with smaller ID with the
//user with bigger ID
void BilkentBeats::sortUsersByAscendingOrder() {
    for(int i = 1; i <= users.getLength(); i++)
        for(int j = 1; j <= users.getLength() - i; j++)
            if(users.getEntry(j).getID() > users.getEntry(j + 1).getID()) {
                User temp(users.getEntry(j));
                users.remove(j);
                users.insert(j + 1, temp);
            }
}

//a method that sorts the users by creating a temporary user object by using the copy constructor in the Song class and swaps the song with smaller ID with the
//song with bigger ID
void BilkentBeats::sortSongsByAscendingOrder() {
    for(int i = 1; i <= songs.getLength(); i++)
        for(int j = 1; j <= songs.getLength() - i; j++)
            if(songs.getEntry(j).getID() > songs.getEntry(j + 1).getID()) {
                Song temp(songs.getEntry(j));
                songs.remove(j);
                songs.insert(j + 1, temp);
            }
}

//a method that adds the given user to the linked list that contains users if the given ID is not already taken
void BilkentBeats::addUser(const int userId, const string userName) {
    int foundUserIndex = -1;

    for(int i = 1; i <= users.getLength(); i++)
        if(users.getEntry(i).getID() == userId)
            foundUserIndex = i;

    if(foundUserIndex != -1)
        cout << "Cannot add user. There is already a user with ID " << users.getEntry(foundUserIndex).getID() << "." << endl;
    else {
        User newUser(userName, userId);
        users.insert(users.getLength() + 1, newUser);
        sortUsersByAscendingOrder();
        cout << "Added user " << userId << "." << endl;
    }
}

//a method that removes the given user if it can be found in the linked list that contains the users
void BilkentBeats::removeUser(const int userId) {
    int foundUserIndex = -1;

    for(int i = 1; i <= users.getLength(); i++)
        if(users.getEntry(i).getID() == userId)
            foundUserIndex = i;

    if(foundUserIndex == -1)
        cout << "Cannot remove user. There is no user with ID " << userId << "." << endl;
    else {
        users.remove(foundUserIndex);
        sortUsersByAscendingOrder();
        cout << "Removed user " << userId << "." << endl;
    }
}

//a method to the print the existing users in the linked list
void BilkentBeats::printUsers() const {
    if(users.getLength() == 0)
        cout << "There are no users to show." << endl;
    else {
        cout << "Users in the system:" << endl;
        for(int i = 1; i <= users.getLength(); i++) {
            string playlistIDs = "[";
            for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength(); j++) {
                if(j != users.getEntry(i).getPlaylists().getLength())
                    playlistIDs += std::to_string(users.getEntry(i).getPlaylists().getEntry(j).getID()) + ",";
                else
                    playlistIDs += std::to_string(users.getEntry(i).getPlaylists().getEntry(j).getID());
            }

            if(users.getEntry(i).getPlaylists().getLength() == 0)
                playlistIDs = "None";
            else
                playlistIDs += "]";

            cout << "User ID : " << users.getEntry(i).getID() << ", Name : " << users.getEntry(i).getName() << ", Playlist IDs : " << playlistIDs << endl;
        }
    }
}

//a method that adds the given song to linked list if the given ID is not already taken
void BilkentBeats::addSong(const int songID, const string songName, const string artists) {
    int foundSongIndex = -1;

    for(int i = 1; i <= songs.getLength(); i++)
        if(songs.getEntry(i).getID() == songID)
            foundSongIndex = i;

    if(foundSongIndex != -1)
        cout << "Cannot add song. BilkentBeats already contains song " << songs.getEntry(foundSongIndex).getID() << "." << endl;
    else {
        Song newSong(songName, artists, songID);
        songs.insert(songs.getLength() + 1, newSong);
        sortSongsByAscendingOrder();
        cout << "Added song " << songID << "." << endl;
    }
}

//a method that removes the given song if it can be found in the linked list that stores the songs
void BilkentBeats::removeSong(const int songID) {
    int foundSongIndex = -1;

    for(int i = 1; i <= songs.getLength(); i++)
        if(songs.getEntry(i).getID() == songID)
            foundSongIndex = i;

    if(foundSongIndex == -1)
        cout << "Cannot remove song. There is no song with ID " << songID << "." << endl;
    else {
        for(int i = 1; i <= users.getLength(); i++)
            for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength(); j++)
                for(int k = 1; k <= users.getEntry(i).getPlaylists().getEntry(j).getSongs().getLength(); k++)
                    if(users.getEntry(i).getPlaylists().getEntry(j).getSongs().getEntry(k).getID() == songID)
                        users.getEntry(i).getPlaylists().getEntry(j).getSongs().remove(k);

        songs.remove(foundSongIndex);
        sortSongsByAscendingOrder();
        cout << "Removed song " << songID << "." << endl;
    }
}

//a method to print the existing songs found in the linked list that stores songs
void BilkentBeats::printSongs() const {
    if(songs.getLength() == 0)
        cout << "Cannot print songs. There is no song in the music library." << endl;
    else {
        cout << "Music Library:" << endl;
        for(int i = 1; i <= songs.getLength(); i++)
            cout << "Song " << songs.getEntry(i).getID() << " : " << songs.getEntry(i).getSongName() << " - " << songs.getEntry(i).getArtistName() << endl;
    }
}

//a method that adds the given playlist to the given user if the given ID for the user can be found and the given ID for the playlist does not already exist
//in a different user
void BilkentBeats::addPlaylist(const int userId, const int playlistId) {
    int foundUserIndex = -1;

    for(int i = 1; i <= users.getLength(); i++)
        if(users.getEntry(i).getID() == userId)
            foundUserIndex = i;

    if(foundUserIndex == -1)
        cout << "Cannot add playlist. There is no user with ID " << userId << "." << endl;
    else {
        bool userAlreadyHasGivenPlaylistID = false;
        for(int i = 1; i <= users.getLength() && !userAlreadyHasGivenPlaylistID; i++) {
            for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength() && !userAlreadyHasGivenPlaylistID; j++) {
                if(users.getEntry(i).getPlaylists().getEntry(j).getID() == playlistId)
                    userAlreadyHasGivenPlaylistID = true;
            }
        }

        if(userAlreadyHasGivenPlaylistID)
            cout << "Cannot add playlist. There is a user having a playlist with ID " << playlistId << "." << endl;
        else {
            Playlist newPlaylist(playlistId, &users.getEntry(foundUserIndex));
            users.getEntry(foundUserIndex).getPlaylists().insert(users.getEntry(foundUserIndex).getPlaylists().getLength() + 1, newPlaylist);
            users.getEntry(foundUserIndex).sortPlaylistsByAscendingOrder();
            cout << "Added playlist " << playlistId << " to user " << userId << "." << endl;
        }
    }
}

//a method to remove the given playlist if the given user ID can be found and the given playlist ID can be found for the given user
void BilkentBeats::removePlaylist(const int userId, const int playlistId) {
    int foundUserIndex = -1;

    for(int i = 1; i <= users.getLength(); i++)
        if(users.getEntry(i).getID() == userId)
            foundUserIndex = i;

    if(foundUserIndex == -1)
        cout << "Cannot remove playlist. There is no user with ID " << userId << "." << endl;
    else {
        int foundPlaylistIndex = -1;
        for(int j = 1; j <= users.getEntry(foundUserIndex).getPlaylists().getLength(); j++)
            if(users.getEntry(foundUserIndex).getPlaylists().getEntry(j).getID() == playlistId)
              foundPlaylistIndex = j;

        if(foundPlaylistIndex == -1)
            cout << "Cannot remove playlist. User " << userId << " does not have a playlist with ID " << playlistId << "." <<endl;
        else {
            users.getEntry(foundUserIndex).getPlaylists().remove(foundPlaylistIndex);
            users.getEntry(foundUserIndex).sortPlaylistsByAscendingOrder();
            cout << "Removed playlist " << playlistId << " from user " << userId << "." << endl;
        }
    }
}

//a method to add the given song to the given playlist if the given ID for the song can be found in the linked list that stores the song objects, the
//given ID for the playlist is valid and the given song does not already exist in the given playlist
void BilkentBeats::addSongToPlaylist(const int playlistId, const int songId) {
    int foundSongIndex = -1;

    for(int i = 1; i <= songs.getLength(); i++)
        if(songs.getEntry(i).getID() == songId)
            foundSongIndex = i;

    if(foundSongIndex == -1)
        cout << "Cannot add song. There is no song with ID " << songId << "." << endl;
    else {
        int foundPlaylistIndex = -1;
        int foundUserIndex = -1;
        for(int i = 1; i <= users.getLength() && foundPlaylistIndex == -1; i++) {
            for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength() && foundPlaylistIndex == -1; j++) {
                if(users.getEntry(i).getPlaylists().getEntry(j).getID() == playlistId) {
                    foundPlaylistIndex = j;
                    foundUserIndex = i;
                }
            }
        }

        if(foundPlaylistIndex == -1)
            cout << "Cannot add song. There is no playlist with ID " << playlistId << "." << endl;
        else {
            int foundSongInPlaylistIndex = -1;
            for(int i = 1; i <= users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getLength(); i++)
                if(users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getEntry(i).getID() == songId)
                    foundSongInPlaylistIndex = i;

            if(foundSongInPlaylistIndex != -1)
                cout << "Cannot add song. The playlist already contains song " << songId << "." << endl;
            else {
                int insertingIndex = users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getLength() + 1;
                users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().insert(insertingIndex, songs.getEntry(foundSongIndex));
                cout << "Added song " << songId << " to playlist " << playlistId << "." << endl;
            }
        }
    }
}

//a method to remove the given song from the given playlist if the given ID for the playlist is valid and the given song exists in the given playlist
void BilkentBeats::removeSongFromPlaylist(const int playlistId, const int songId) {
    int foundPlaylistIndex = -1;
    int foundUserIndex = -1;
    for(int i = 1; i <= users.getLength() && foundPlaylistIndex == -1; i++) {
        for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength() && foundPlaylistIndex == -1; j++) {
            if(users.getEntry(i).getPlaylists().getEntry(j).getID() == playlistId) {
                foundPlaylistIndex = j;
                foundUserIndex = i;
            }
        }
    }

    if(foundPlaylistIndex == -1)
        cout << "Cannot remove song. There is no playlist with ID " << playlistId << "." << endl;
    else {
        int foundSongInPlaylistIndex = -1;
        for(int i = 1; i <= users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getLength(); i++)
            if(users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getEntry(i).getID() == songId)
                foundSongInPlaylistIndex = i;

        if(foundSongInPlaylistIndex == -1)
            cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << endl;
        else {
            users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().remove(foundSongInPlaylistIndex);
            cout << "Removed song " << songId << " from playlist " << playlistId << "." << endl;
        }
    }
}

//a method that prints all the songs found in the given playlist if the given ID for the playlist is valid
void BilkentBeats::printSongsInPlaylist(const int playlistId) const {
    int foundPlaylistIndex = -1;
    int foundUserIndex = -1;
    for(int i = 1; i <= users.getLength() && foundPlaylistIndex == -1; i++) {
        for(int j = 1; j <= users.getEntry(i).getPlaylists().getLength() && foundPlaylistIndex == -1; j++) {
            if(users.getEntry(i).getPlaylists().getEntry(j).getID() == playlistId) {
                foundPlaylistIndex = j;
                foundUserIndex = i;
            }
        }
    }

    if(foundPlaylistIndex == -1)
        cout << "Cannot print songs. There is no playlist with ID " << playlistId << "." << endl;
    else {
        if(users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getLength() == 0)
            cout << "There are no songs to show in playlist " << playlistId << "." << endl;
        else {
            cout << "Songs in playlist " << playlistId << ":" << endl;
            for(int i = 1; i <= users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getLength(); i++) {
                string name = users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getEntry(i).getSongName();
                string artist = users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getEntry(i).getArtistName();
                int ID = users.getEntry(foundUserIndex).getPlaylists().getEntry(foundPlaylistIndex).getSongs().getEntry(i).getID();
                cout << "Song " << ID << " : " << name << " - " << artist << endl;
            }
        }
    }
}
