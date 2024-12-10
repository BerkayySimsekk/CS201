//Berkay Simsek 22303338
#include "Playlist.h"

Playlist::Playlist() {
    ID = -1;
    user = nullptr;
}

Playlist::~Playlist() {
    for(int i = 1; i <= songs.getLength(); i++) {
        songs.remove(i);
        i--;
    }
}

Playlist::Playlist(Playlist& aPlaylist) {
    user = aPlaylist.getAssignedUser();
    ID = aPlaylist.ID;

    for(int i = 1; i <= aPlaylist.getSongs().getLength(); i++)
        songs.insert(i, aPlaylist.getSongs().getEntry(i));
}

Playlist::Playlist(const int playlistID, User* assignedUser) {
    ID = playlistID;
    user = assignedUser;
}

int Playlist::getID() const {
    return ID;
}

User* Playlist::getAssignedUser() {
    return user;
}

LinkedList<Song>& Playlist::getSongs() {
    return songs;
}
